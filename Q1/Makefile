IDIR =./include
CXX=g++

CPPFLAGS=-I$(IDIR) -std=c++11 -O3 -w 
LDFLAGS=-I$(IDIR) -std=c++11 -O3 -w
CURLFLAG=-lcurl

SRC_DIR = ./src
OBJ_DIR = ./obj
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
BIN_SRC_DIR = ./bin_src
BIN_DIR = ./bin

all: main example

main: $(OBJ_FILES) | $(BIN_DIR)
	$(CXX)  $(CPPFLAGS) -c -o ./obj/main.o target/main.cpp
	$(CXX)  $(LDFLAGS) -o $(BIN_DIR)/$@ $^ ./obj/main.o $(CURLFLAG)

example: $(OBJ_FILES) | $(BIN_DIR)
	$(CXX)  $(CPPFLAGS) -c -o ./obj/example.o target/example.cpp
	$(CXX)  $(LDFLAGS) -o $(BIN_DIR)/$@ $^ ./obj/example.o $(CURLFLAG)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX)  $(CPPFLAGS) -c -o $@ $<

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
