target=scanner
CC=g++
CXXFLAGS += -std=c++17 -I /usr/local/include/antlr4-runtime -I./src/frontend -g -w
LIBS += -lantlr4-runtime -L /usr/local/lib

# Source files
SRCS = src/main.cpp src/frontend/common.h src/frontend/Display.h src/frontend/utils.h src/frontend/ast.h src/frontend/ast.cpp src/frontend/AstRewriter.h src/frontend/AstRewriter.cpp src/frontend/AstVisitor.h src/frontend/AstVisitor.cpp src/frontend/SysyBaseListener.cpp src/frontend/SysyBaseVisitor.cpp src/frontend/SysyLexer.cpp src/frontend/SysyListener.cpp src/frontend/SysyParser.cpp src/frontend/SysyVisitor.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(target)

$(target): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) $(CXXFLAGS)

%.o: %.cpp
	$(CC) -c $< -o $@ $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f src/frontend/*.o src/main.o scanner test_cases/*.ast.txt src/Sysy*.*
    