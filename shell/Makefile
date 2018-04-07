OBJS	= main.o
SUBDIR	= shell



all:shell_obj.o
shell_obj.o:$(OBJS)
	@echo " [LD] $(SUBDIR)/$@"
	$(Q)$(LD)  -r -o $@ $^
	
%.o:%.c
	@echo " [CC] $(SUBDIR)/$@"
	echo "jeff"
	$(Q)$(CC) $(CFLAGS) -c -o $@ $<

%.d:%.c
	@set -e; rm -f $@; $(CC) -MM $< $(INCFLAGS) > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
	
-include $(OBJS:.o=.d)


.PHONY:clean

clean:
	rm -f *.o
