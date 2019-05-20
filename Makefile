cc ?= cc
CFLAGS = -std=c99 -O3 -Wall
LDFALGS = 
EXAMPLES_DIR = examples
TEST_DIR = tests

.PHONY: run-example
run-example:
	$(CC) $(CFLAGS) -o $(EXAMPLES_DIR)/example $(EXAMPLES_DIR)/main.c map.c
	./$(EXAMPLES_DIR)/example

.PHONY: test
test:
	$(CC) -o $(TEST_DIR)/tests $(TEST_DIR)/tests.c map.c $(TEST_DIR)/unity/unity.c
	$(TEST_DIR)/tests
	rm -f $(TEST_DIR)/tests

.PHONY: clean
clean:
	rm -f $(EXAMPLES_DIR)/example
	rm -f $(TEST_DIR)/tests
