CC			= gcc
CFLAGS		= -g -Wall
INCLUDES	= 
LDFLAGS		= 
LIBS		= 
OBJS		= create_str.o
PROGRAM		= create_str

$(PROGRAM):	$(OBJS)
			$(CC) $(LDFLAGS) $(LIBS) $(OBJS) -o $(PROGRAM)

create_str:	create_str.c	
			$(CC) $(CFLAGS) $(INCLUDES) $@.c -o $@

clean:;		rm -f *.o *~ $(PROGRAM)