CC = gcc
CFLAGS = -Wall -O2
PROG_MASTER = master
PROG_SLAVE  = slave
OBJS = point.o

all: $(PROG_MASTER) $(PROG_SLAVE)

$(PROG_MASTER): master.o $(OBJS)
	$(CC) -o $@ master.o $(OBJS) -lpvm3

$(PROG_SLAVE): slave.o $(OBJS)
	$(CC) -o $@ slave.o $(OBJS) -lpvm3

%.o: %.c point.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o master slave points_gnuplot uh_gnuplot upper_hull.pdf