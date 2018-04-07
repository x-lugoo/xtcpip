NET_STACK_OBJS=shell/shell_obj.o	

LD = ld
CC = gcc
Q = 
CFLAGS = -Wall  -I../include 
LFLAGS = -lpthread

export LD CC CFLAGS


all:xtcpip
xtcpip:$(NET_STACK_OBJS)
	@echo " [BUILD] $@"
	$(Q)$(CC)  $^ -o $@			


shell/shell_obj.o:shell/*.c
	make -C shell/



.PHONY:clean
clean:
	find . -name *.o | xargs rm -f
	find . -name *.d | xargs rm -f
	find . -name *.d.* | xargs rm -f
	rm -f xtcpip
