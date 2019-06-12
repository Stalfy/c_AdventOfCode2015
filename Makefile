CC = gcc
CFLAGS = -Wall -fPIC -fopenmp -m64 -O3
LFLAGS = -Wall -fPIC -fopenmp -m64

BUILD_DIR = build
SRC_DIR = src

SRC = $(shell find $(SRC_DIR)/ -name '*.c')
OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

EXE = app

RM = rm -r
MKDIR_P = mkdir -p

all: $(OBJ)
	$(CC) $(LFLAGS) -o $(EXE) $^

clean:
	$(RM) $(BUILD_DIR)/ $(EXE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
