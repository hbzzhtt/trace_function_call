#include <stdio.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

//如果关注的一行backtrace位于一个可执行文件中，那么直接addr2line -e <executable> <address>

/* 如果关注的backtrace位于一个动态链接库中，那么麻烦一些，因为动态链接库的基地址不是固定的。
 * 这个时候，首先要把进程的memory map找来。在Linux下，进程的memory map可以在/proc/<pid>/maps文件中得到。
 * 然后在这个文件中找到动态链接库的基地址，然后将backtrace中的地址 - 动态链接库的基地址，得到偏移地址offset address,
 * 最后addr2line -e <shared library> <offset address>。 */

static FILE *fp_trace;

void __attribute__((constructor,no_instrument_function)) traceBegin(void) {
    char buff[64] = {0x00};

    sprintf(buff,"cat /proc/%d/maps > func_trace.out", getpid());

    system((const char*) buff);

    fp_trace = fopen("func_trace.out", "a");

}

void __attribute__((destructor,no_instrument_function)) traceEnd(void) {
    if (fp_trace != NULL) {
        fclose(fp_trace);
    }
}

void __attribute__((no_instrument_function))__cyg_profile_func_enter(void *func, void *caller) {
        /* fprintf(fp_trace, "enter func: %p father: %p\n", func, caller); */
    Dl_info info1, info2;
    if (dladdr(func, &info1) && dladdr(caller, &info2))
        fprintf(fp_trace, "enter func: %s father: %s\n", info1.dli_sname, info2.dli_sname);

}

void __attribute__((no_instrument_function))__cyg_profile_func_exit(void *func, void *caller) {
        /* fprintf(fp_trace, "exit func: %p father: %p\n", func, caller); */
    Dl_info info1, info2;
    if (dladdr(func, &info1) && dladdr(caller, &info2))
        fprintf(fp_trace, "exit func: %s father: %s\n", info1.dli_sname, info2.dli_sname);
}
