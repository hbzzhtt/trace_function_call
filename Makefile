
CFLAGS+= -D_GNU_SOURCE -g -ggdb -O0 -finstrument-functions -ldl -rdynamic 
c:  main.o trace.o
	gcc  $^ -o  $@ ${CFLAGS}
	rm $^
	echo "make c complete"

cpp:   main.oc trace.oc
	g++  $^ -o  $@ ${CFLAGS}
	rm $^
	echo "make cpp complete"

clean:
	rm -rf c cpp 

%.o: %.c 
	gcc  -c $^ -o $@ ${CFLAGS}

%.oc: %.cc 
	g++  -c $^ -o $@ ${CFLAGS}

# $@

# 表示目标集，“集”的意思就是组合，全部，有多个目标，$@就是目标集合。

# $^

# 所有依赖目标的集合，注意，这里说的是“依赖”，也就是目标的组成元素。

# $<

# 依赖目标中的第一个目标名字，也就是上面说的$^中的第一个元素。
