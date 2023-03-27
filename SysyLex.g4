lexer grammar SysyLex;

// keyword
INT : 'int';
FLOAT : 'float';
VOID : 'void';
CONST : 'const';
RETURN : 'return';
IF : 'if';
ELSE : 'else';
FOR : 'for';
WHILE : 'while';
DO : 'do';
BREAK : 'break';
CONTINUE : 'continue'; 

// delimeter
LP : '(' ;
RP : ')' ;
LB : '[' ;
RB : ']' ;
LC : '{' ;
RC : '}' ;
COMMA : ',' ;
SEMICOLON : ';';
QUESTION : '?';
COLON : ':';

// operator
MINUS : '-';
NOT : '!';
ASSIGN : '=';
ADD : '+';
MUL : '*';
DIV : '/';
MOD : '%';
AND : '&&';
OR : '||';
EQ : '==';
NEQ : '!=';
LT : '<';
LE : '<=';
GT : '>';
GE : '>=';

// integer literal
INT_LIT
    : [1-9][0-9]*
    | '0'[0-7]*
    | '0x'[0-9a-fA-F]+
    | '0X'[0-9a-fA-F]+
    ;

// float literal
FLOAT_LIT
    :  ([0-9]*'.'[0-9]+|[0-9]+'.') EXP? [fF]?
    |[0-9]+ EXP [fF]?
    ;

// fragment for float literal
fragment
EXP :  [eE] [+-]? [0-9]+ ;

// identifier
ID
    : [a-zA-Z_][a-zA-Z_0-9]*
    ;

// string
STRING : '"'(ESC|.)*?'"';

// for string
fragment
ESC : '\\"'|'\\\\';

// whitespace
WS : 
    [ \t\r\n] -> skip
    ;

// comments
LINE_COMMENT : '//' .*? '\r'? '\n' -> skip;
BLOCK_COMMENT : '/*'.*?'*/'-> skip ;

// obvious lexical error
LEX_ERR :  [0-9]+[a-zA-Z]*[0-9]* 
        ;

