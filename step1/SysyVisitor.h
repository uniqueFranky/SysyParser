
// Generated from Sysy.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "SysyParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SysyParser.
 */
class  SysyVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SysyParser.
   */
    virtual antlrcpp::Any visitCompUnit(SysyParser::CompUnitContext *context) = 0;

    virtual antlrcpp::Any visitCompUnitItem(SysyParser::CompUnitItemContext *context) = 0;

    virtual antlrcpp::Any visitDecl(SysyParser::DeclContext *context) = 0;

    virtual antlrcpp::Any visitConstDecl(SysyParser::ConstDeclContext *context) = 0;

    virtual antlrcpp::Any visitInt(SysyParser::IntContext *context) = 0;

    virtual antlrcpp::Any visitFloat(SysyParser::FloatContext *context) = 0;

    virtual antlrcpp::Any visitConstDef(SysyParser::ConstDefContext *context) = 0;

    virtual antlrcpp::Any visitVarDecl(SysyParser::VarDeclContext *context) = 0;

    virtual antlrcpp::Any visitVarDef(SysyParser::VarDefContext *context) = 0;

    virtual antlrcpp::Any visitInit(SysyParser::InitContext *context) = 0;

    virtual antlrcpp::Any visitInitList(SysyParser::InitListContext *context) = 0;

    virtual antlrcpp::Any visitFuncDef(SysyParser::FuncDefContext *context) = 0;

    virtual antlrcpp::Any visitFuncType_(SysyParser::FuncType_Context *context) = 0;

    virtual antlrcpp::Any visitVoid(SysyParser::VoidContext *context) = 0;

    virtual antlrcpp::Any visitFuncFParams(SysyParser::FuncFParamsContext *context) = 0;

    virtual antlrcpp::Any visitScalarParam(SysyParser::ScalarParamContext *context) = 0;

    virtual antlrcpp::Any visitArrayParam(SysyParser::ArrayParamContext *context) = 0;

    virtual antlrcpp::Any visitBlock(SysyParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitBlockItem(SysyParser::BlockItemContext *context) = 0;

    virtual antlrcpp::Any visitAssign(SysyParser::AssignContext *context) = 0;

    virtual antlrcpp::Any visitExprStmt(SysyParser::ExprStmtContext *context) = 0;

    virtual antlrcpp::Any visitBlockStmt(SysyParser::BlockStmtContext *context) = 0;

    virtual antlrcpp::Any visitIfElse(SysyParser::IfElseContext *context) = 0;

    virtual antlrcpp::Any visitWhile(SysyParser::WhileContext *context) = 0;

    virtual antlrcpp::Any visitBreak(SysyParser::BreakContext *context) = 0;

    virtual antlrcpp::Any visitContinue(SysyParser::ContinueContext *context) = 0;

    virtual antlrcpp::Any visitReturn(SysyParser::ReturnContext *context) = 0;

    virtual antlrcpp::Any visitExp(SysyParser::ExpContext *context) = 0;

    virtual antlrcpp::Any visitCond(SysyParser::CondContext *context) = 0;

    virtual antlrcpp::Any visitLVal(SysyParser::LValContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryExp_(SysyParser::PrimaryExp_Context *context) = 0;

    virtual antlrcpp::Any visitLValExpr(SysyParser::LValExprContext *context) = 0;

    virtual antlrcpp::Any visitDecIntConst(SysyParser::DecIntConstContext *context) = 0;

    virtual antlrcpp::Any visitOctIntConst(SysyParser::OctIntConstContext *context) = 0;

    virtual antlrcpp::Any visitHexIntConst(SysyParser::HexIntConstContext *context) = 0;

    virtual antlrcpp::Any visitDecFloatConst(SysyParser::DecFloatConstContext *context) = 0;

    virtual antlrcpp::Any visitHexFloatConst(SysyParser::HexFloatConstContext *context) = 0;

    virtual antlrcpp::Any visitNumber(SysyParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitUnaryExp_(SysyParser::UnaryExp_Context *context) = 0;

    virtual antlrcpp::Any visitCall(SysyParser::CallContext *context) = 0;

    virtual antlrcpp::Any visitUnaryAdd(SysyParser::UnaryAddContext *context) = 0;

    virtual antlrcpp::Any visitUnarySub(SysyParser::UnarySubContext *context) = 0;

    virtual antlrcpp::Any visitNot(SysyParser::NotContext *context) = 0;

    virtual antlrcpp::Any visitStringConst(SysyParser::StringConstContext *context) = 0;

    virtual antlrcpp::Any visitFuncRParam(SysyParser::FuncRParamContext *context) = 0;

    virtual antlrcpp::Any visitFuncRParams(SysyParser::FuncRParamsContext *context) = 0;

    virtual antlrcpp::Any visitDiv(SysyParser::DivContext *context) = 0;

    virtual antlrcpp::Any visitMod(SysyParser::ModContext *context) = 0;

    virtual antlrcpp::Any visitMul(SysyParser::MulContext *context) = 0;

    virtual antlrcpp::Any visitMulExp_(SysyParser::MulExp_Context *context) = 0;

    virtual antlrcpp::Any visitAddExp_(SysyParser::AddExp_Context *context) = 0;

    virtual antlrcpp::Any visitAdd(SysyParser::AddContext *context) = 0;

    virtual antlrcpp::Any visitSub(SysyParser::SubContext *context) = 0;

    virtual antlrcpp::Any visitGeq(SysyParser::GeqContext *context) = 0;

    virtual antlrcpp::Any visitLt(SysyParser::LtContext *context) = 0;

    virtual antlrcpp::Any visitRelExp_(SysyParser::RelExp_Context *context) = 0;

    virtual antlrcpp::Any visitLeq(SysyParser::LeqContext *context) = 0;

    virtual antlrcpp::Any visitGt(SysyParser::GtContext *context) = 0;

    virtual antlrcpp::Any visitNeq(SysyParser::NeqContext *context) = 0;

    virtual antlrcpp::Any visitEq(SysyParser::EqContext *context) = 0;

    virtual antlrcpp::Any visitEqExp_(SysyParser::EqExp_Context *context) = 0;

    virtual antlrcpp::Any visitLAndExp_(SysyParser::LAndExp_Context *context) = 0;

    virtual antlrcpp::Any visitAnd(SysyParser::AndContext *context) = 0;

    virtual antlrcpp::Any visitOr(SysyParser::OrContext *context) = 0;

    virtual antlrcpp::Any visitLOrExp_(SysyParser::LOrExp_Context *context) = 0;


};

