
CC = clang
CFLAGS = -Wall -Wextra -g


TARGETS = shell coreutils/clear coreutils/date coreutils/mv coreutils/rmdir coreutils/cat coreutils/cp coreutils/ls coreutils/mkdir coreutils/pwd coreutils/rm coreutils/touch


all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)

.PHONY: all clean
