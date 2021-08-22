CC      = g++
CFLAGS  = -Icompat -Wno-narrowing

Z88DK_HOME = /usr/local/share/z88dk
Z88DK_TARGET = cpm -lm -lndos -subtype=zxplus3

CC      = $(Z88DK_HOME)/bin/zcc
CFLAGS  = +$(Z88DK_TARGET)
LDFLAGS = +$(Z88DK_TARGET) -create-app -pragma-define:CRT_COMMANDLINE_REDIRECTION=0
#LDFLAGS = +$(Z88DK_TARGET) -lm -lcpccpm -create-app --generic-console -pragma-define:CONSOLE_COLUMNS=51 -pragma-define:CONSOLE_ROWS=24

PROG = sync
OBJS = dos.o $(PROG).o

.PHONY: all format clean

all: $(PROG)

$(PROG): $(OBJS) 
	PATH=$(Z88DK_HOME)/bin:$(PATH) $(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	PATH=$(Z88DK_HOME)/bin:$(PATH) $(CC) $(CFLAGS) -c $< -o $@

format: $(wildcard *.c) $(wildcard *.h)
	clang-format -i $^

clean:
	rm $(PROG) $(OBJS)
