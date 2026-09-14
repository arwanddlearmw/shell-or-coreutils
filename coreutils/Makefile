
CC = clang
CFLAGS = -Wall -Wextra -g


TARGETS = cat clear cp date ls mkdir pwd shell


all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)

.PHONY: all clean