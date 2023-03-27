target=scanner
objs=SysyBaseListener.o SysyBaseVisitor.o SysyLexer.o SysyListener.o SysyParser.o SysyVisitor.o main.o
CC=g++
CXXFLAGS += -std=c++17 -I /usr/local/include/antlr4-runtime -g
LIBS += -lantlr4-runtime -L /usr/local/lib

main:$(objs)
	$(CC) -o $(target)  $(objs) $(LIBS) $(CXXFLAGS)
%.o:%.cpp
	$(CC) -c $< $(CXXFLAGS)