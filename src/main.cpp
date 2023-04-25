#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <map>
#include <string>
#include "antlr4-runtime.h"
#include "SysyParser.h"
#include "SysyLexer.h"
#include "SysyBaseVisitor.h"
#include "SysyBaseListener.h"
#include "AstVisitor.h"
#include "AstRewriter.h"

using namespace std;
using namespace antlr4;
using namespace frontend;

int main(int argc, const char* argv[]) {
    ifstream stream(argv[1]); //读入测试用例
    ANTLRInputStream input(stream);  
    SysyLexer lexer(&input);  //词法解析
    CommonTokenStream tokens(&lexer);  //生成TokenStream
    SysyParser parser(&tokens);   //语法解析
    auto root = parser.compUnit();   //得到AST的根节点
    frontend::AstVisitor visitor;   //自己重写过的AstVisitor类对象
    visitor.visitCompUnit(root);   //visitor模式中从根节点开始遍历
    auto ast = visitor.compileUnit();   
    AstRewriter rewriter;   //可以根据需要对AST rewrite
    rewriter.visit_compile_unit(*ast);
    string output_file_name = string(argv[1]) + ".ast.txt";
    ofstream of;
    of.open(output_file_name);
    ast->print(of,0);   //打印AST

    return 0;
}
