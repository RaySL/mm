CC = g++

CURRENT_DIRECTORY = $(shell pwd)

CFLAGS = -I$(CURRENT_DIRECTORY) -std=gnu++11
LDFLAGS =

HDRS = $(shell find . -name "*.h" -o -name "*.tpp")
OBJS = client.o

all: client

client: $(OBJS)
	$(CC) -o client $(OBJS) $(LDFLAGS)

%.o: %.cpp $(HDRS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJS)
