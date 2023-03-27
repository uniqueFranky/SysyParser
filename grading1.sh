#!/bin/bash

cd step1

if [ ! -f "parser" ];then
  make
fi

read -p '' case
chmod +x parser
./parser ../test_cases/case_$case.sy