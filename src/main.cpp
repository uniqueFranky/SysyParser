#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <map>
#include "antlr4-runtime.h"
#include "frontend/SysyParser.h"
#include "frontend/SysyLexer.h"
#include "frontend/SysyBaseVisitor.h"
#include "frontend/SysyBaseListener.h"
#include "frontend/AstVisitor.h"
#include "frontend/AstRewriter.h"

using namespace std;
using namespace antlr4;
using namespace frontend;

int main(int argc, const char* argv[]) {
    ifstream stream(argv[1]);
    ANTLRInputStream input(stream);
    SysyLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    SysyParser parser(&tokens);
    auto root = parser.compUnit();
    frontend::AstVisitor visitor;
    visitor.visitCompUnit(root);
    auto ast = visitor.compileUnit();
    AstRewriter rewriter;
    rewriter.visit_compile_unit(*ast);
    ast->print(cout,0);

    return 0;
}
