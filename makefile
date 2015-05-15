
OBJS=ff.c diskio.c  sd.c main.c

xf:$(OBJS) ffconf.h 
	$(CC) -o $@ $^ -g -Wall

clean:
	rm -rf *.o xf
