SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)


%: %.c
	gcc $< -O0 -std=c99 -o $@

.PHONY: clean
clean:
	rm $(PROGS)