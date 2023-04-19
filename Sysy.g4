grammar Sysy;

import SysyLex;

compUnit : compUnitItem* EOF;
compUnitItem
    : decl
    | funcDef
    ;

//在这里补充你的语法规则，注意每条语法规则的首字母一定是小写字母！参照Sysy2022语言文法定义