target=parser
objs=SysyBaseListener.o SysyBaseVisitor.o SysyLexer.o SysyListener.o SysyParser.o SysyVisitor.o main.o
CC=g++
CXXFLAGS += -std=c++17 
LIBS += -lantlr4-runtime 

$(target):$(objs)
	$(CC) -o $(target)  $(objs) $(LIBS)
%.o:%.cpp
	$(CC) -c $< $(CXXFLAGS)
.PHONY: clean    
clean:
	rm parser Sysy*.* main.o -f
