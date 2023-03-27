#!/bin/bash

cd step1

if [ ! -f "parser" ];then
  make 2>&1 >/dev/null
fi

read -p '' case
chmod +x parser
./parser ../test_cases/case_$case.sy