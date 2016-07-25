OBJS = runscreated.o
CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -c -Wall $(DEBUG)
LFLAGS = -Wall $(DEBUG)

runscreated : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o runscreated

runscreated.o : runscreated.cpp
	$(CC) $(CFLAGS) runscreated.cpp

clean:
	\rm *.o *~ runscreated
