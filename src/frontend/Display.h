#pragma once

#include <ostream>
#include <sstream>

class Display {  //用于输出的基类，遍历AST上的点如果要输出，则继承此类，并实现print方法
public:
    virtual ~Display() = default;

    [[nodiscard]] std::string to_string() const {
        std::ostringstream buffer;
        this->print(buffer, 0);
        return buffer.str();
    }

    virtual void print(std::ostream &out, unsigned indent) const = 0;  

    friend std::ostream &operator<<(std::ostream &out, Display const &self) {
        self.print(out, 0);
        return out;
    }
};
