#include <cassert>
#include <memory>
#include <string>
#include <any>
#include "utils.h"
#include "AstVisitor.h"
#include "ast.h"

using namespace frontend;

std::unique_ptr<CompileUnit> AstVisitor::compileUnit() {
    return std::move(m_compile_unit);
}

antlrcpp::Any
AstVisitor::visitCompUnit(SysyParser::CompUnitContext *const ctx) {
    std::vector<CompileUnit::Child> children;
    for (auto item : ctx->compUnitItem()) {
        if (auto decl = item->decl()) {
            auto const decls = decl->accept(this).as<std::shared_ptr<std::vector<Declaration *>>>();
            for (auto d : *decls) {
                children.emplace_back(std::unique_ptr<Declaration>(d));
            }
        } else if (auto func_ = item->funcDef()) {
            auto const func = (func_->accept(this)).as<Function *>();
            children.emplace_back(std::unique_ptr<Function>(func));
        } else {
            assert(false);
        }
    }
    auto compile_unit = new CompileUnit(std::move(children));
    m_compile_unit.reset(compile_unit);
    return compile_unit;
}

antlrcpp::Any
AstVisitor::visitConstDecl(SysyParser::ConstDeclContext *const ctx) {
    auto const base_type_ = (ctx->bType()->accept(this)).as<ScalarType *>();
    std::unique_ptr<ScalarType> base_type(base_type_);
    std::vector<Declaration *> ret;
    for (auto def : ctx->constDef()) {
        Identifier ident(def->Ident()->getText());
        auto dimensions = this->visitDimensions(def->exp());
        std::unique_ptr<SysYType> type;
        if (dimensions.empty()) {
            type = std::make_unique<ScalarType>(*base_type);
        } else {
            type = std::make_unique<ArrayType>(*base_type, std::move(dimensions), false);
        }
        auto const init_ = (def->initVal()->accept(this)).as<Initializer *>();
        std::unique_ptr<Initializer> init(init_);
        ret.push_back(new Declaration(std::move(type), std::move(ident),
                                      std::move(init), true));
    }
    return std::make_shared<std::vector<Declaration *>>(std::move(ret));
}

antlrcpp::Any AstVisitor::visitInt(SysyParser::IntContext *const ctx) {
    return new ScalarType(Int);
}

antlrcpp::Any AstVisitor::visitFloat(SysyParser::FloatContext *const ctx) {
    return new ScalarType(Float);
}

antlrcpp::Any AstVisitor::visitVarDecl(SysyParser::VarDeclContext *const ctx) {
    auto const base_type_ = (ctx->bType()->accept(this)).as<ScalarType *>();
    std::unique_ptr<ScalarType> base_type(base_type_);
    std::vector<Declaration *> ret;
    for (auto def : ctx->varDef()) {
        Identifier ident(def->Ident()->getText());
        auto dimensions = this->visitDimensions(def->exp());
        std::unique_ptr<SysYType> type;
        if (dimensions.empty()) {
            type = std::make_unique<ScalarType>(*base_type);
        } else {
            type = std::make_unique<ArrayType>(*base_type, std::move(dimensions), false);
        }
        std::unique_ptr<Initializer> init;
        if (auto init_val = def->initVal()) {
            init.reset((init_val->accept(this)).as<Initializer *>());
        }
        ret.push_back(new Declaration(std::move(type), std::move(ident),
                                      std::move(init), false));
    }
    return std::make_shared<std::vector<Declaration *>>(std::move(ret));
}

antlrcpp::Any AstVisitor::visitInit(SysyParser::InitContext *const ctx) {
    auto expr_ = (ctx->exp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> expr(expr_);
    return new Initializer(std::move(expr));
}

antlrcpp::Any
AstVisitor::visitInitList(SysyParser::InitListContext *const ctx) {
    std::vector<std::unique_ptr<Initializer>> values;
    for (auto init : ctx->initVal()) {
        auto const value = (init->accept(this)).as<Initializer *>();
        values.emplace_back(value);
    }
    return new Initializer(std::move(values));
}

antlrcpp::Any AstVisitor::visitFuncDef(SysyParser::FuncDefContext *const ctx) {
    auto const type_ = (ctx->funcType()->accept(this)).as<ScalarType *>();
    std::unique_ptr<ScalarType> type(type_);
    Identifier ident(ctx->Ident()->getText(), false);
    std::vector<std::unique_ptr<Parameter>> params;
    if (auto params_ = ctx->funcFParams()) {
        for (auto param_ : params_->funcFParam()) {
            auto const param = (param_->accept(this)).as<Parameter *>();
            params.emplace_back(param);
        }
    }
    auto const body_ = (ctx->block()->accept(this)).as<Block *>();
    std::unique_ptr<Block> body(body_);
    return new Function(std::move(type), std::move(ident), std::move(params),
                        std::move(body));
}

antlrcpp::Any AstVisitor::visitVoid(SysyParser::VoidContext *const ctx) {
    return static_cast<ScalarType *>(nullptr);
}

antlrcpp::Any
AstVisitor::visitScalarParam(SysyParser::ScalarParamContext *const ctx) {
    auto const type_ = (ctx->bType()->accept(this)).as<ScalarType *>();
    std::unique_ptr<SysYType> type(type_);
    Identifier ident(ctx->Ident()->getText());
    return new Parameter(std::move(type), std::move(ident));
}

antlrcpp::Any AstVisitor::visitArrayParam(SysyParser::ArrayParamContext *ctx) {
    auto const basic_type_ = (ctx->bType()->accept(this)).as<ScalarType *>();
    std::unique_ptr<ScalarType> basic_type(basic_type_);
    Identifier ident(ctx->Ident()->getText());
    auto dimensions = this->visitDimensions(ctx->exp());
    std::unique_ptr<SysYType> type(
            new ArrayType(*basic_type, std::move(dimensions), true));
    return new Parameter(std::move(type), std::move(ident));
}

antlrcpp::Any AstVisitor::visitBlock(SysyParser::BlockContext *const ctx) {
    std::vector<Block::Child> children;
    for (auto item : ctx->blockItem()) {
        if (auto decl = item->decl()) {
            auto const decls = decl->accept(this).as<std::shared_ptr<std::vector<Declaration *>>>();
            for (auto d : *decls) {
                children.emplace_back(std::unique_ptr<Declaration>(d));
            }
        } else if (auto stmt_ = item->stmt()) {
            auto const stmt = (stmt_->accept(this)).as<Statement *>();
            children.emplace_back(std::unique_ptr<Statement>(stmt));
        } else {
            assert(false);
        }
    }
    return new Block(std::move(children));
}

antlrcpp::Any AstVisitor::visitAssign(SysyParser::AssignContext *const ctx) {
    auto const lhs_ = (ctx->lVal()->accept(this)).as<LValue *>();
    std::unique_ptr<LValue> lhs(lhs_);
    auto const rhs_ = (ctx->exp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> rhs(rhs_);
    auto const ret = new Assignment(std::move(lhs), std::move(rhs));
    return static_cast<Statement *>(ret);
}

antlrcpp::Any
AstVisitor::visitExprStmt(SysyParser::ExprStmtContext *const ctx) {
    std::unique_ptr<Expression> expr;
    if (auto expr_ = ctx->exp()) {
        expr.reset((expr_->accept(this)).as<Expression *>());
    }
    auto const ret = new ExprStmt(std::move(expr));
    return static_cast<Statement *>(ret);
}

antlrcpp::Any
AstVisitor::visitBlockStmt(SysyParser::BlockStmtContext *const ctx) {
    auto const ret = (ctx->block()->accept(this)).as<Block *>();
    return static_cast<Statement *>(ret);
}

antlrcpp::Any AstVisitor::visitIfElse(SysyParser::IfElseContext *const ctx) {
    auto const cond_ = (ctx->cond()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> cond(cond_);
    auto const then_ = (ctx->stmt(0)->accept(this)).as<Statement *>();
    std::unique_ptr<Statement> then(then_);
    std::unique_ptr<Statement> else_;
    if (ctx->Else() != nullptr) {
        else_.reset((ctx->stmt(1)->accept(this)).as<Statement *>());
    }
    auto const ret = new IfElse(std::move(cond), std::move(then), std::move(else_));
    return static_cast<Statement *>(ret);
}

// TODO: Complete this method correctly by filling in the parameters
antlrcpp::Any AstVisitor::visitWhile(SysyParser::WhileContext *const ctx) {
    auto const cond_ = (ctx->cond()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> cond(cond_);
    auto const body_ = (ctx->stmt()->accept(this)).as<Statement *>();
    std::unique_ptr<Statement> body(body_);
    auto ret = new While(std::move(cond), std::move(body));
    return static_cast<Statement *>(ret);
}

antlrcpp::Any
AstVisitor::visitBreak(SysyParser::BreakContext *const ctx) {
    auto const ret = new Break();
    return static_cast<Statement *>(ret);
}

antlrcpp::Any
AstVisitor::visitContinue(SysyParser::ContinueContext *const ctx) {
    auto const ret = new Continue();
    return static_cast<Statement *>(ret);
}

antlrcpp::Any
AstVisitor::visitReturn(SysyParser::ReturnContext *const ctx) {
    std::unique_ptr<Expression> expr;
    if (ctx->exp() != nullptr) {
        expr.reset((ctx->exp()->accept(this)).as<Expression *>());
    }
    auto const ret = new Return(std::move(expr));
    return static_cast<Statement *>(ret);
}


antlrcpp::Any
AstVisitor::visitLVal(SysyParser::LValContext *ctx) {
    auto ident = Identifier(ctx->Ident()->getText());
    std::vector<std::unique_ptr<Expression>> indices;
    for(const auto &index: ctx->exp()) {
        auto expr_ = (index->accept(this)).as<Expression *>();
        std::unique_ptr<Expression> expr(expr_);
        indices.push_back(std::move(expr));
    }
    return new LValue(ident, std::move(indices));
}

antlrcpp::Any
AstVisitor::visitPrimaryExp_(SysyParser::PrimaryExp_Context *ctx) {
    if(ctx->exp() != nullptr) {
        return ctx->exp()->accept(this);
    } else {
        assert(ctx->number() != nullptr);
        if(ctx->number()->intConst() != nullptr) {
            auto lit = (ctx->number()->intConst()->accept(this)).as<IntLiteral *>();
            return static_cast<Expression *>(lit);
        } else {
            assert(ctx->number()->floatConst() != nullptr);
            auto lit = (ctx->number()->floatConst()->accept(this)).as<FloatLiteral *>();
            return static_cast<Expression *>(lit);
        }

    }
}

antlrcpp::Any
AstVisitor::visitLValExpr(SysyParser::LValExprContext *ctx) {
    auto lval_ = (ctx->lVal()->accept(this)).as<LValue *>();
    return static_cast<Expression *>(lval_);
}

antlrcpp::Any
AstVisitor::visitDecIntConst(SysyParser::DecIntConstContext *ctx) {
    int val = std::stoi(ctx->getText(), nullptr, 10);
    return new IntLiteral(val);
}

antlrcpp::Any
AstVisitor::visitOctIntConst(SysyParser::OctIntConstContext *ctx) {
    int val = std::stoi(ctx->getText(), nullptr, 8);
    return new IntLiteral(val);
}

antlrcpp::Any
AstVisitor::visitHexIntConst(SysyParser::HexIntConstContext *ctx) {
    int val = std::stoi(ctx->getText(), nullptr, 16);
    return new IntLiteral(val);
}

antlrcpp::Any
AstVisitor::visitDecFloatConst(SysyParser::DecFloatConstContext *ctx) {
    float val = std::stof(ctx->getText());
    return new FloatLiteral(val);
}

antlrcpp::Any
AstVisitor::visitHexFloatConst(SysyParser::HexFloatConstContext *ctx) {
    float val = std::strtof(ctx->getText().c_str(), nullptr);
    return new FloatLiteral(val);
}

antlrcpp::Any
AstVisitor::visitCall(SysyParser::CallContext *ctx) {
    Identifier ident(ctx->Ident()->getText(), false);
    std::vector<Call::Argument> args;
    for(const auto &arg: ctx->funcRParams()->funcRParam()) {
        if(arg->exp() != nullptr) {
            auto expr_ = (arg->exp()->accept(this)).as<Expression *>();
            std::unique_ptr<Expression> expr(expr_);
            args.emplace_back(std::move(expr));
        } else {
            assert(arg->stringConst() != nullptr);
            auto str = (arg->stringConst()->accept(this)).as<StringLiteral>();
            args.emplace_back(std::move(str));
        }
    }
    return static_cast<Expression *>(new Call(ident, std::move(args), ctx->getStart()->getLine()));
}

antlrcpp::Any
AstVisitor::visitUnaryAdd(SysyParser::UnaryAddContext *ctx) {
    auto unary_ = (ctx->unaryExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> unary(unary_);
    return static_cast<Expression *>(new UnaryExpr(UnaryOp::Add, std::move(unary)));
}

antlrcpp::Any
AstVisitor::visitUnarySub(SysyParser::UnarySubContext *ctx) {
    auto unary_ = (ctx->unaryExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> unary(unary_);
    return static_cast<Expression *>(new UnaryExpr(UnaryOp::Sub, std::move(unary)));
}

antlrcpp::Any
AstVisitor::visitNot(SysyParser::NotContext *ctx) {
    auto unary_ = (ctx->unaryExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> unary(unary_);
    return static_cast<Expression *>(new UnaryExpr(UnaryOp::Not, std::move(unary)));
}

antlrcpp::Any
AstVisitor::visitStringConst(SysyParser::StringConstContext *ctx) {
    return std::move(StringLiteral(ctx->getText()));
}

antlrcpp::Any
AstVisitor::visitDiv(SysyParser::DivContext *ctx) {
    auto mul_ = (ctx->mulExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> mul(mul_);
    auto unary_ = (ctx->unaryExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> unary(unary_);
    return static_cast<Expression *>(new BinaryExpr(BinaryOp::Div, std::move(mul), std::move(unary)));
}

antlrcpp::Any
AstVisitor::visitMod(SysyParser::ModContext *ctx) {
    auto mul_ = (ctx->mulExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> mul(mul_);
    auto unary_ = (ctx->unaryExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> unary(unary_);
    return static_cast<Expression *>(new BinaryExpr(BinaryOp::Mod, std::move(mul), std::move(unary)));
}

antlrcpp::Any
AstVisitor::visitMul(SysyParser::MulContext *ctx) {
    auto mul_ = (ctx->mulExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> mul(mul_);
    auto unary_ = (ctx->unaryExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> unary(unary_);
    return static_cast<Expression *>(new BinaryExpr(BinaryOp::Mul, std::move(mul), std::move(unary)));
}

antlrcpp::Any
AstVisitor::visitAdd(SysyParser::AddContext *ctx) {
    auto add_ = (ctx->addExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> add(add_);
    auto mul_ = (ctx->mulExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> mul(mul_);
    return static_cast<Expression *>(new BinaryExpr(BinaryOp::Add, std::move(add), std::move(mul)));
}

antlrcpp::Any
AstVisitor::visitSub(SysyParser::SubContext *ctx) {
    auto add_ = (ctx->addExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> add(add_);
    auto mul_ = (ctx->mulExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> mul(mul_);
    return static_cast<Expression *>(new BinaryExpr(BinaryOp::Sub, std::move(add), std::move(mul)));
}

antlrcpp::Any
AstVisitor::visitGeq(SysyParser::GeqContext *ctx) {
    auto rel_ = (ctx->relExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> rel(rel_);
    auto add_ = (ctx->addExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> add(add_);
    return static_cast<Expression *>(new BinaryExpr(BinaryOp::Geq, std::move(rel), std::move(add)));
}

antlrcpp::Any
AstVisitor::visitLt(SysyParser::LtContext *ctx) {
    auto rel_ = (ctx->relExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> rel(rel_);
    auto add_ = (ctx->addExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> add(add_);
    return static_cast<Expression *>(new BinaryExpr(BinaryOp::Lt, std::move(rel), std::move(add)));
}

antlrcpp::Any
AstVisitor::visitLeq(SysyParser::LeqContext *ctx) {
    auto rel_ = (ctx->relExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> rel(rel_);
    auto add_ = (ctx->addExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> add(add_);
    return static_cast<Expression *>(new BinaryExpr(BinaryOp::Leq, std::move(rel), std::move(add)));
}

antlrcpp::Any
AstVisitor::visitGt(SysyParser::GtContext *ctx) {
    auto rel_ = (ctx->relExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> rel(rel_);
    auto add_ = (ctx->addExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> add(add_);
    return static_cast<Expression *>(new BinaryExpr(BinaryOp::Gt, std::move(rel), std::move(add)));
}

antlrcpp::Any
AstVisitor::visitNeq(SysyParser::NeqContext *ctx) {
    auto eq_ = (ctx->eqExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> eq(eq_);
    auto rel_ = (ctx->relExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> rel(rel_);
    return static_cast<Expression *>(new BinaryExpr(BinaryOp::Neq, std::move(eq), std::move(rel)));
}

antlrcpp::Any
AstVisitor::visitEq(SysyParser::EqContext *ctx) {
    auto eq_ = (ctx->eqExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> eq(eq_);
    auto rel_ = (ctx->relExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> rel(rel_);
    return static_cast<Expression *>(new BinaryExpr(BinaryOp::Eq, std::move(eq), std::move(rel)));
}

antlrcpp::Any
AstVisitor::visitAnd(SysyParser::AndContext *ctx) {
    auto lAnd_ = (ctx->lAndExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> lAnd(lAnd_);
    auto eq_ = (ctx->eqExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> eq(eq_);
    return static_cast<Expression *>(new BinaryExpr(BinaryOp::And, std::move(lAnd), std::move(eq)));
}

antlrcpp::Any
AstVisitor::visitOr(SysyParser::OrContext *ctx) {
    auto lOr_ = (ctx->lOrExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> lOr(lOr_);
    auto lAnd_ = (ctx->lAndExp()->accept(this)).as<Expression *>();
    std::unique_ptr<Expression> lAnd(lAnd_);
    return static_cast<Expression *>(new BinaryExpr(BinaryOp::And, std::move(lOr), std::move(lAnd)));
}

antlrcpp::Any
AstVisitor::visitNumber(SysyParser::NumberContext *ctx) {
    assert(false);
}

std::vector<std::unique_ptr<Expression>>
AstVisitor::visitDimensions(const std::vector<SysyParser::ExpContext *> &ctxs) {
    std::vector<std::unique_ptr<Expression>> ret;
    for(auto const &ctx: ctxs) {
        auto expr_ = (ctx->accept(this)).as<Expression *>();
        std::unique_ptr<Expression> expr(expr_);
        ret.push_back(std::move(expr));
    }
    return std::move(ret);
}