CC = gcc
CFLAGS = -Wall -fPIC -m64 -O3
LFLAGS = -Wall -fPIC -m64

SRC_DIR = src
TEST_DIR = test

BUILD_DIR = build
SRC_BUILD_DIR = $(BUILD_DIR)/$(SRC_DIR)
TEST_BUILD_DIR = $(BUILD_DIR)/$(TEST_DIR)

SRC = $(SRC_DIR)/main.c $(wildcard $(SRC_DIR)/**/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(SRC_BUILD_DIR)/%.o,$(SRC))

TEST_SRC = $(TEST_DIR)/main.c $(wildcard $(TEST_DIR)/**/*.c) $(filter-out $(SRC_DIR)/main.c,$(SRC))
TEST_OBJ = $(patsubst $(SRC_DIR)/%.c,$(SRC_BUILD_DIR)/%.o,$(filter $(SRC_DIR)/%.c, $(TEST_SRC))) \
		   $(patsubst $(TEST_DIR)/%.c,$(TEST_BUILD_DIR)/%.o,$(filter $(TEST_DIR)/%.c, $(TEST_SRC)))

EXE = aoc2015

RM = rm -r
MKDIR_P = mkdir -p

.PHONY: all test clean

all: $(OBJ)
	$(CC) $(LFLAGS) -o $(EXE) $^

test: $(TEST_OBJ)
	$(CC) $(LFLAGS) -o $(EXE) $^

clean:
	$(RM) $(BUILD_DIR)/ $(EXE)

$(SRC_BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
