    CC     = gcc -std=c11 -g
    CFLAGS = -Wall
    LFLAGS =

      PROG = floodit_v1
      OBJS = functions.o \
             $(PROG).o

.PHONY: limpa faxina clean distclean purge all

%.o: %.c %.h functions.h
	$(CC) -c $(CFLAGS) $<

$(PROG):  $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

clean:
	@rm -f *~ *.bak

purge:   clean
	@rm -f *.o core a.out
	@rm -f $(PROG)