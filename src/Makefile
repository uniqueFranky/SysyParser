target=parser
CC=g++
CXXFLAGS += -std=c++17  -g -w
LIBS += -lantlr4-runtime

# Source files
SRCS = main.cpp ast.cpp AstVisitor.cpp SysyBaseListener.cpp SysyBaseVisitor.cpp SysyLexer.cpp SysyListener.cpp SysyParser.cpp SysyVisitor.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(target)

$(target): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) 

%.o: %.cpp
	$(CC) -c $< -o $@ $(CXXFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJS) Sysy*.* parser
    