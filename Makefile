CC			= gcc
CFLAGS		= -g -Wall
INCLUDES	= 
LDFLAGS		= 
LIBS		= 
OBJS		= main.o create_str.o
PROGRAM		= create_str

$(PROGRAM):	$(OBJS)
			$(CC) $(LDFLAGS) $(LIBS) $(OBJS) -o $(PROGRAM) 

clean:;		rm -f *.o *~ $(PROGRAM)
