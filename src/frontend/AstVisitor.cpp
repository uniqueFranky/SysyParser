#include <cassert>
#include <memory>
#include <string>

#include "utils.h"
#include "AstVisitor.h"
#include "ast.h"

using namespace frontend;

std::unique_ptr<CompileUnit> AstVisitor::compileUnit() {
    return std::move(m_compile_unit);
}

antlrcpp::Any
AstVisitor::visitCompUnit(SysyParser::CompUnitContext *const ctx) {

}

antlrcpp::Any
AstVisitor::visitConstDecl(SysyParser::ConstDeclContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitInt(SysyParser::IntContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitFloat(SysyParser::FloatContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitVarDecl(SysyParser::VarDeclContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitInit(SysyParser::InitContext *const ctx) {

}

antlrcpp::Any
AstVisitor::visitInitList(SysyParser::InitListContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitFuncDef(SysyParser::FuncDefContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitVoid(SysyParser::VoidContext *const ctx) {

}

antlrcpp::Any
AstVisitor::visitScalarParam(SysyParser::ScalarParamContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitArrayParam(SysyParser::ArrayParamContext *ctx) {

}

antlrcpp::Any AstVisitor::visitBlock(SysyParser::BlockContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitAssign(SysyParser::AssignContext *const ctx) {

}

antlrcpp::Any
AstVisitor::visitExprStmt(SysyParser::ExprStmtContext *const ctx) {

}

antlrcpp::Any
AstVisitor::visitBlockStmt(SysyParser::BlockStmtContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitIfElse(SysyParser::IfElseContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitWhile(SysyParser::WhileContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitBreak(SysyParser::BreakContext *const ctx) {

}

antlrcpp::Any
AstVisitor::visitContinue(SysyParser::ContinueContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitReturn(SysyParser::ReturnContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitLVal(SysyParser::LValContext *const ctx) {

}

antlrcpp::Any
AstVisitor::visitPrimaryExp_(SysyParser::PrimaryExp_Context *const ctx) {

}

antlrcpp::Any
AstVisitor::visitLValExpr(SysyParser::LValExprContext *const ctx) {

}

antlrcpp::Any
AstVisitor::visitDecIntConst(SysyParser::DecIntConstContext *const ctx) {

}

antlrcpp::Any
AstVisitor::visitOctIntConst(SysyParser::OctIntConstContext *const ctx) {

}

antlrcpp::Any
AstVisitor::visitHexIntConst(SysyParser::HexIntConstContext *const ctx) {

}

antlrcpp::Any
AstVisitor::visitDecFloatConst(SysyParser::DecFloatConstContext *const ctx) {

}

antlrcpp::Any
AstVisitor::visitHexFloatConst(SysyParser::HexFloatConstContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitCall(SysyParser::CallContext *const ctx) {

}

antlrcpp::Any
AstVisitor::visitUnaryAdd(SysyParser::UnaryAddContext *const ctx) {

}

antlrcpp::Any
AstVisitor::visitUnarySub(SysyParser::UnarySubContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitNot(SysyParser::NotContext *const ctx) {

}

antlrcpp::Any
AstVisitor::visitStringConst(SysyParser::StringConstContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitMul(SysyParser::MulContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitDiv(SysyParser::DivContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitMod(SysyParser::ModContext *const ctx) {


antlrcpp::Any AstVisitor::visitAdd(SysyParser::AddContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitSub(SysyParser::SubContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitLt(SysyParser::LtContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitGt(SysyParser::GtContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitLeq(SysyParser::LeqContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitGeq(SysyParser::GeqContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitEq(SysyParser::EqContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitNeq(SysyParser::NeqContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitAnd(SysyParser::AndContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitOr(SysyParser::OrContext *const ctx) {

}

antlrcpp::Any AstVisitor::visitNumber(SysyParser::NumberContext *const ctx) {

}

std::vector<std::unique_ptr<Expression>>
AstVisitor::visitDimensions(const std::vector<SysyParser::ExpContext *> &ctxs) {

}
