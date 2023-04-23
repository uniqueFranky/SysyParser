#include <iostream>

#include "antlr4-runtime.h"
#include "SysyLexer.h"
#include "SysyBaseListener.h"
#include "SysyBaseVisitor.h"
#include "SysyParser.h"
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
        
        //V.push_back(make_pair(line,msg));

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

    if (V.empty()) {
        cout << "no error! please check your g4 file" << endl;
        return 0;
    }

    sort(V.begin(),V.end());
    auto file_name = string(argv[1]);
    auto slash_pos = file_name.find_last_of("/");
    file_name = file_name.substr(slash_pos + 1);
    cout << file_name << ":" << V.begin()->first << endl;

    return 0;
}    