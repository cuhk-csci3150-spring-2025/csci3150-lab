SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	gcc $< -O0 -std=c11 -o $@

.PHONY: clean
clean:
	rm $(PROGS)