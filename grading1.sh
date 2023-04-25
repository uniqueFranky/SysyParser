#!/bin/bash

cd src

make 2>&1 >/dev/null


read -p '' case
chmod +x parser
./parser ../test_cases/case_$case.sy