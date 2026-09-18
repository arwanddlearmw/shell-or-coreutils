
CC = clang
CFLAGS = -Wall -Wextra -g


TARGETS = coreutils/ls

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)

.PHONY: all clean
