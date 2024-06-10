SRC_DIR = ./src
INC_DIR = ./inc
OUT_DIR = ./build
OBJ_DIR = $(OUT_DIR)/obj
DOCS_DIR = $(OUT_DIR)/doc

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

.DEFAULT_GOAL := all

-include $(patsubst %.o,%.d,$(OBJ_FILES))

all: $(OBJ_FILES)
	@echo Enlazando $@
	@gcc $(OBJ_FILES) -o $(OUT_DIR)/app.elf

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compilando $@
	@mkdir -p $(OBJ_DIR)
	@gcc -o $@ -c $< -I $(INC_DIR) -MMD -D GPIO_MAX_INSTANCES=20

doc: $(SRC_DIR)/*.c $(INC_DIR)/*.h doxyfile
	@mkdir -p $(DOCS_DIR)
	@doxygen doxyfile

clean:
	@rm -r $(OUT_DIR)
