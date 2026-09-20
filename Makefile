CC = cc
CFLAGS = -Wall -Wextra -g

BIN = bin

PROGRAMS = \
	shell \
	cat \
	clear \
	cp \
	date \
	ls \
	mkdir \
	mv \
	pwd \
	rm \
	rmdir \
	touch

TARGETS = $(addprefix $(BIN)/,$(PROGRAMS))

all: $(TARGETS)

$(BIN):
	mkdir -p $(BIN)

$(BIN)/shell: shell.c | $(BIN)
	$(CC) $(CFLAGS) $< -o $@

$(BIN)/%: coreutils/%.c | $(BIN)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)

.PHONY: all clean
