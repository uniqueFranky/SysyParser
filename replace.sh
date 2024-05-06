#!/bin/bash

# 定义输入和输出文件
input_file="src/AstVisitor.cpp"
output_file="a_modified.cpp"

# 使用正则表达式替换 std::any_cast<T>(val) 为 (val).as<T>()
sed -E 's/std::any_cast<([^>]+)>\((.+)\)/(\2).as<\1>()/g' "$input_file" > "$output_file"

echo "替换完成：生成了新的文件 $output_file"
