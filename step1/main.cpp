#include <iostream>

#include "antlr4-runtime.h"
#include "SysyLexer.h"
#include "SysyBaseListener.h"
#include "SysyBaseVisitor.h"
#include "SysyParser.h"
#include "main.h"
#include "ANTLRInputStream.h"
#include "CommonTokenStream.h"
#include <vector>
#include <map>

using namespace antlr4;
using namespace std;

map<size_t,bool> is_occured;
vector<pair<size_t,string>> V;

class MyErrorListener : public BaseErrorListener {
public:
    void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine, const std::string &msg, std::exception_ptr e) override {
        //std::cout << "Error at line " << line << ": " << msg << std::endl;
        if (is_occured.find(line) == is_occured.end()) {
            is_occured[line] = true;
            V.push_back(make_pair(line,msg));
        }
    }
};

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    SysyLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    // 语法分析
    SysyParser parser(&tokens);
    MyErrorListener errorListener;
    parser.removeErrorListeners();
    parser.addErrorListener(&errorListener);

    parser.compUnit();
    sort(V.begin(),V.end());
    auto line = V.begin();
    cout << "Error at line " << line->first << endl << line->second << endl;

    //std::cout << tree->toStringTree(&parser) << std::endl << std::endl;


    return 0;
}    