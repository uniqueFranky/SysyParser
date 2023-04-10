#pragma once

#include "ast.h"

namespace frontend {

    class AstRewriter {
    public:
        void visit_compile_unit(ast::CompileUnit &);
        void visit_block(ast::Block &);
    };

}
