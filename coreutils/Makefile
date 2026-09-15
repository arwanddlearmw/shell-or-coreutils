
CC = clang
CFLAGS = -Wall -Wextra -g


TARGETS = cat.c  clear.c  cp.c  date.c  hello.sh  ls.c  mkdir.c  pwd.c  rm.c  rmdir.c  shell.c 


all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)

.PHONY: all clean