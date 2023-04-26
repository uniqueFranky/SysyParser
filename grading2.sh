#!/bin/bash

#ake clean 2>&1 >/dev/null
cd src
make 2>&1 >/dev/null

if [ ! -f "parser" ]; then
  echo "无法编译得到分析程序scanner"
else
  read -p '' case
  chmod +x parser
  ./parser -ast  ../test_cases/$case
fi