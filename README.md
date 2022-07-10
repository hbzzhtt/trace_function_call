# trace_function_call
trace c/c++ function call graph

use `make c` to create a c function call example
a c example is like:
```
enter func: main father: __libc_start_main
enter func: bar() father: main
enter func: zoo(int) father: bar()
enter func: foo(double) father: zoo(int)
exit func: foo(double) father: zoo(int)
exit func: zoo(int) father: bar()
exit func: bar() father: main
exit func: main father: __libc_start_main
```

use `make cpp` to create a c function call example
a cpp example is like:
```
enter func: main father: __libc_start_main
enter func: bar() father: main
enter func: zoo(int) father: bar()
enter func: foo(double) father: zoo(int)
exit func: foo(double) father: zoo(int)
exit func: zoo(int) father: bar()
exit func: bar() father: main
exit func: main father: __libc_start_main
```
