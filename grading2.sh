#!/bin/bash

make -s clean
make -s

if [ ! -f "scanner" ]; then
  echo "无法编译得到分析程序scanner"
else
  read -p '' case
  chmod +x scanner ./test_cases/$case
    if [ $(cat ./test_cases/${case}.ast.txt | grep -c "main") -eq 0 ];
      then
      echo "AST not correctly dumpped!"
      cat ./test_cases/${case}.ast.txt
    else
      echo "AST file saved in $case.ast.txt:"
      cat ./test_cases/${case}.ast.txt
    fi

fi