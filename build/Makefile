all:echo_server

echo_server:

%.d:%.c
	@set -e; rm -f $@;\
		$(CC) -M $(CPPFLAGS) $< > $@.$$$$;\
		sed 's,\($*\)\.o[ :]*,\l.o $@:.,g' < $@.$$$$ > $@;\
		rm -f $@.$$$$
