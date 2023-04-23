#pragma once

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <list>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define TypeCase(res, type, expr) if (auto res = dynamic_cast<type>(expr))

enum class UnaryOp { 
    // 你定义的一元运算的语法规则，注释中的为示例，根据你的需要改写
    Add, Sub, Not
     };

enum class BinaryOp {
    Add,
    Sub,
    Mul,
    Div,
    Mod,
    Eq,
    Neq,
    Lt,
    Gt,
    Leq,
    Geq,
    And,
    Or,
    Shr,
    Shl,
    NR_OPS
    
   // 意义类同上面的UnaryOp，NR_OPS作为哨兵，当visit AST时遇到的二元运算符的标号大于等于NR_OPS时，报错
   // TODO: your code
};

enum ScalarType {
   
    Int,
    Float,
    String,
   
   // 标量类型，根据你的需要改写。
   // TODO: your code
};

struct Type {
    // 类表示一般类型，成员变量base_type是上面代码中enum中的一个整数，表示一种类型
    int base_type;
    // 是否是常量
    bool is_const;
    // dims用于保存数组，结合下面的成员函数理解
    std::vector<int> dims; // 数组第一维可以是0

    int nr_dims() const { return dims.size(); }
    bool is_array() const { return dims.size() > 0; }
    int nr_elems() const {
        int count = 1;
        for (int n : dims)
            count *= n;
        return count;
    }
    int size() const { return nr_elems() * 4; }
    //以下重载了一些运算符
    bool operator==(const Type &b) const {
        if (base_type != b.base_type)
            return false;
        if (nr_dims() != b.nr_dims())
            return false;
        for (int i = 0; i < nr_dims(); i++) {
            if (dims[i] != b.dims[i])
                return false;
        }
        return true;
    }
    bool operator!=(const Type &b) const { return !this->operator==(b); }
    //得到指针的类型
    Type get_pointer_type() const {
        Type new_type = *this;
        new_type.dims.insert(new_type.dims.begin(), 0);
        return new_type;
    }
    bool is_pointer() const { return dims.size() > 0 && dims[0] == 0; }
    bool is_pointer_to_scalar() const { return dims.size() == 1 && dims[0] == 0; }

    //一些构造函数
    Type() {}
    Type(int btype) : base_type{btype}, is_const{false} {}
    Type(int btype, bool const_qualified)
            : base_type{btype}, is_const{const_qualified} {}
    Type(int btype, std::vector<int> dimensions)
            : base_type{btype}, is_const{false}, dims{std::move(dimensions)} {}
    Type(Type type, std::vector<int> dimensions)
            : base_type{type.base_type}, is_const{false}, dims{
            std::move(dimensions)} {
        assert(!type.is_array());
    }
};

// std::variant过于难用，这里直接用union
// 此ConstValue特指标量，在一个union中可以存int类型的值，也可以存float类型的值
struct ConstValue {
    int type;
    union {
        int iv;
        float fv;
    };

    ConstValue() {}
    
    // 以下被注释掉的成员函数和成员函数中被注释掉的部分需要根据你的语法规则来进行改写
    // TODO: your code

    // 构造函数
    ConstValue(int v) : type{Int} { iv = v; }
    ConstValue(float v) : type{Float} { fv = v; }

    // check ConstValue == 0 / 1
    bool isValue(int x) const {
        if (type == Int) {
            return iv == x;
        } else {
            return fv == x;
        }
       
    }

    bool isOpposite(const ConstValue &b) const {
      
        if (type != b.type)
            return false;
        if (type == Int)
            return iv + b.iv == 0;
        if (type == Float)
            return fv + b.fv == 0;
        assert(false);
        return false;
      
    }

    ConstValue getOpposite() const {
      
        ConstValue new_const = (*this);
        if (type == Int) {
            new_const.iv = -new_const.iv;
        } else if (type == Float) {
            new_const.fv = -new_const.fv;
        } else
            assert(false);
        return new_const;
     
    }

    bool operator==(const ConstValue &b) const {
    
        if (type != b.type)
            return false;
        if (type == Int)
            return iv == b.iv;
        if (type == Float)
            return fv == b.fv;
        // 如果运行到这里，说明代码出现问题
        assert(false);
        return false;
     
    }
    bool operator!=(const ConstValue &b) const { return !this->operator==(b); }

    std::string to_string() const {
      
        if (type == Int)
            return std::to_string(iv);
        if (type == Float)
            return std::to_string(fv);
        assert(false);
       
    }
};

namespace std {
    template <> class hash<ConstValue> {
    public:
        size_t operator()(const ConstValue &r) const { return r.iv; }
    };
} // namespace std

// Var类表示一个变量或者是一个常量
struct Var {
    Type type;
    std::optional<ConstValue> val;
    std::unique_ptr<std::map<int, ConstValue>>
            arr_val; // index -> value，未记录的项全部初始化为0

    Var() {}
    Var(Type type_) : type{std::move(type_)} {}
    Var(Type type_, std::optional<ConstValue> value)
            : type{std::move(type_)}, val{std::move(value)} {}
};

//重写的Hash函数，用于STL的容器，你可以不用关注这一部分
namespace std {
    template <class T> struct hash<vector<T>> {
        size_t operator()(const vector<T> &r) const {
            size_t res = 0;
            for (auto t : r) {
                res = res * 1221821 + hash<T>()(t);
            }
            return res;
        }
    };
    template <> class hash<Type> {
    public:
        size_t operator()(const Type &r) const {
            return hash<int>()(r.base_type) * 17 + hash<std::vector<int>>()(r.dims);
        }
    };
} // namespace std

inline bool is_power_of_2(int x) { return (x & (x - 1)) == 0; }
