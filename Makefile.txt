# Compiler and flags
CXX       := clang++
CXXFLAGS  := -std=c++23 -Wall -Wextra -Wpedantic
CPPFLAGS  := -Iinclude -MMD -MP
LDFLAGS   :=
LDLIBS    :=

# Directories and target
SRC_DIR   := src
OBJ_DIR   := obj
BIN_DIR   := build
TARGET    := $(BIN_DIR)/game
COMPDB    := compile_commands.json

# Discover all .cpp files recursively in SRC_DIR
SRCS      := $(shell find $(SRC_DIR) -name '*.cpp')
# Map src/path/file.cpp -> obj/path/file.o
OBJS      := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
# Track header dependencies (.d files generated alongside .o files)
DEPS      := $(OBJS:.o=.d)
# Track compile command fragments (.o.json generated alongside .o files)
JSONS     := $(OBJS:.o=.o.json)

# Default target
all: $(TARGET) $(COMPDB)

# Link the executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

# Generate compile_commands.json from compilation fragments
$(COMPDB): $(OBJS)
	@echo "Generating $@"
	@sed -e '1s/^/[\n/' -e '$$s/,\s*$$/\n]/' $(JSONS) > $@.tmp
	@mv $@.tmp $@

compiledb: $(COMPDB)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MJ $@.json -c $< -o $@

# Create output directories if they don't exist
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Include auto-generated dependency rules
-include $(DEPS)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(COMPDB)

# Rebuild from scratch
re: clean all

.PHONY: all clean re compiledb
