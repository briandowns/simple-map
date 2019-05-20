cc ?= cc
CFLAGS = -std=c99 -O3 -Wall
LDFALGS = 
EXAMPLES_DIR = examples

.PHONY: run-example
run-example:
	$(CC) $(CFLAGS) -o $(EXAMPLES_DIR)/example $(EXAMPLES_DIR)/main.c map.c
	./$(EXAMPLES_DIR)/example

.PHONY: test
test:
	$(CC) -o tests/tests tests/tests.c map.c tests/unity/unity.c
	tests/tests
	rm -f tests/tests

.PHONY: clean
clean:
	rm -f $(EXAMPLES_DIR)/example
