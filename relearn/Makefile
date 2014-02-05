CC = g++
CFLAGS = -Wall -g -std=gnu++11
LDFLAGS = 

all: haunt
	
clean:
	rm *.o
	rm haunt

spark:
	${CC} ${CFLAGS} -c spark.cpp

world:
	${CC} ${CFLAGS} -c world.cpp	

main: world
	${CC} ${CFLAGS} -c main.cpp

haunt: spark main
	${CC} ${CFLAGS} *.o ${LDFLAGS} -o haunt