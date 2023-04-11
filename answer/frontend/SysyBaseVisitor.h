
// Generated from Sysy.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "SysyVisitor.h"


/**
 * This class provides an empty implementation of SysyVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SysyBaseVisitor : public SysyVisitor {
public:

  virtual antlrcpp::Any visitCompUnit(SysyParser::CompUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompUnitItem(SysyParser::CompUnitItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecl(SysyParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstDecl(SysyParser::ConstDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInt(SysyParser::IntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloat(SysyParser::FloatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstDef(SysyParser::ConstDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDecl(SysyParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDef(SysyParser::VarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInit(SysyParser::InitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitList(SysyParser::InitListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncDef(SysyParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncType_(SysyParser::FuncType_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVoid(SysyParser::VoidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncFParams(SysyParser::FuncFParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScalarParam(SysyParser::ScalarParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayParam(SysyParser::ArrayParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(SysyParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlockItem(SysyParser::BlockItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign(SysyParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprStmt(SysyParser::ExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlockStmt(SysyParser::BlockStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfElse(SysyParser::IfElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhile(SysyParser::WhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBreak(SysyParser::BreakContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContinue(SysyParser::ContinueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturn(SysyParser::ReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExp(SysyParser::ExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCond(SysyParser::CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLVal(SysyParser::LValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimaryExp_(SysyParser::PrimaryExp_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLValExpr(SysyParser::LValExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecIntConst(SysyParser::DecIntConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOctIntConst(SysyParser::OctIntConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHexIntConst(SysyParser::HexIntConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecFloatConst(SysyParser::DecFloatConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHexFloatConst(SysyParser::HexFloatConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(SysyParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryExp_(SysyParser::UnaryExp_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCall(SysyParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryAdd(SysyParser::UnaryAddContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnarySub(SysyParser::UnarySubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNot(SysyParser::NotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringConst(SysyParser::StringConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncRParam(SysyParser::FuncRParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncRParams(SysyParser::FuncRParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDiv(SysyParser::DivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMod(SysyParser::ModContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMul(SysyParser::MulContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulExp_(SysyParser::MulExp_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddExp_(SysyParser::AddExp_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdd(SysyParser::AddContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSub(SysyParser::SubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGeq(SysyParser::GeqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLt(SysyParser::LtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelExp_(SysyParser::RelExp_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLeq(SysyParser::LeqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGt(SysyParser::GtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNeq(SysyParser::NeqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEq(SysyParser::EqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqExp_(SysyParser::EqExp_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLAndExp_(SysyParser::LAndExp_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnd(SysyParser::AndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOr(SysyParser::OrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLOrExp_(SysyParser::LOrExp_Context *ctx) override {
    return visitChildren(ctx);
  }


};

