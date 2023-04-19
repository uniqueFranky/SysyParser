#include "AstRewriter.h"

namespace frontend {

    void AstRewriter::visit_compile_unit(ast::CompileUnit &node) {
        for (auto &child : node.children()) {
            if (child.index() == 1) {
                auto &func = std::get<std::unique_ptr<ast::Function>>(child);
                visit_block(*func->body());
            }
        }
    }

    void AstRewriter::visit_block(ast::Block &node) {
        using Block = ast::Block;
        using Child = ast::Block::Child;
        auto &children = node.m_children;
        auto as_if_else = [&](Child &c) -> ast::IfElse * {
            if (c.index() != 1)
                return nullptr;
            auto &stmt = std::get<std::unique_ptr<ast::Statement>>(c);
            return dynamic_cast<ast::IfElse *>(stmt.get());
        };
        auto get_head_index = [&]() {
            for (int i = 0; i < children.size() - 1; ++i) {
                auto i1 = as_if_else(children[i]);
                auto i2 = as_if_else(children[i + 1]);
                if (!i1 || !i2)
                    continue;

                if (i1->cond()->to_string() == i2->cond()->to_string())
                    return i;
            }
            return -1;
        };
        int i;
        while ((i = get_head_index()) >= 0) {
            auto i1 = as_if_else(children[i]);
            auto i2 = as_if_else(children[i + 1]);
            std::vector<Child> blk_t, blk_f;
            if (i1->m_then)
                blk_t.push_back(std::move(i1->m_then));
            if (i2->m_then)
                blk_t.push_back(std::move(i2->m_then));
            if (i1->m_else)
                blk_f.push_back(std::move(i1->m_else));
            if (i2->m_else)
                blk_f.push_back(std::move(i2->m_else));
            i1->m_then.reset(new Block{std::move(blk_t)});
            i1->m_else.reset(new Block{std::move(blk_f)});
            children.erase(children.begin() + (i + 1));
        }
    }

}
