SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	gcc $< -O0 -std=11 -o $@

.PHONY: clean
clean:
	rm $(PROGS)