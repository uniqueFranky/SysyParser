#pragma once

#include <variant>

#include "Display.h"
#include "common.h"

namespace frontend {
    namespace ast {

        using UnaryOp = ::UnaryOp;
        using BinaryOp = ::BinaryOp;

        class SysYType : public Display {
        public:
        private:
        };

        class ScalarType : public SysYType {
        public:
        private:
        };

        class Expression;

        class ArrayType : public SysYType {
        public:
        private:
        };

        class Identifier : public Display {
        public:
        private:
        };

        class Parameter : public Display {
        public:
        private:
        };

        class AstNode : public Display {
        public:
        private:
        };

        class NumberLiteral;

        class Expression : public AstNode {
        public:
        private:
        };

        class LValue : public Expression {
        public:
        private:
        };

        class UnaryExpr : public Expression {
        public:
        private:
        };

        class BinaryExpr : public Expression {
        public:
        private:
        };

        class Literal : public Expression {
        public:
        private:
        };

        class NumberLiteral : public Literal {
        public:
        private:
        };

        class IntLiteral : public NumberLiteral {
        public:
        private:
        };

        class FloatLiteral : public NumberLiteral {
        public:
        private:
        };

        class StringLiteral : AstNode {
        public:
        private:
        };

        class Call : public Expression {
        public:
        private:
        };

        class Statement : public AstNode {
        public:
        private:
        };

        class ExprStmt : public Statement {
        public:
        private:
        };

        class Assignment : public Statement {
        public:
        private:
        };

        class Initializer : public AstNode {
        public:
        private:
        };

        class Declaration : public AstNode {
        public:
        private:
        };

        class Block : public Statement {
        public:
        private:
        };

        class IfElse : public Statement {
        public:
        private:
        };

        class While : public Statement {
        public:
        private:
        };

        class Break : public Statement {
        public:
        private:
        };

        class Continue : public Statement {
        public:
        private:
        };

        class Return : public Statement {
        public:
        private:
        };

        class Function : public AstNode {
        public:
        private:
        };

        class CompileUnit : public AstNode {
        public:
        private:
        };

    } // namespace ast
} // namespace frontend
