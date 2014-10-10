%{
#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
#include "treewalk.h"
#include "tabelasimbolos-declaracoes.h"
#include "tabelasimbolos-funcoes.h"
#include "tabelasimbolos-funcoes-parametros.h"
#include "tabelasimbolos-estruturas.h"
#include "tabelasimbolos-estruturas-declaracoes.h"
#include "tabelasimbolos-estruturas-funcoes.h"
#include "tabelasimbolos-estruturas-funcoes-parametros.h"

extern "C"{ 
  extern int yyerror(char*); 
  extern int yylex(); 
  
} 
Ast* ast;
TabelaVariaveis *raizVariaveis;
TabelaFuncoes *raizFuncoes;
int escopo;
int erro;
//char *nomefuncao;
int ordem;

#include "funcoesauxiliares.h"
%}


%union{
Ast* ast;
            int type;
char *idname;
int line;
}


%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN 

%token STRUCT_TYPE

%type <ast> primary_expression
%type <ast> postfix_expression
%type <ast> argument_expression_list
%type <ast> unary_expression
%type <ast> unary_operator
%type <ast> cast_expression
%type <ast> multiplicative_expression
%type <ast> additive_expression
%type <ast> shift_expression
%type <ast> relational_expression
%type <ast> equality_expression
%type <ast> and_expression
%type <ast> exclusive_or_expression
%type <ast> inclusive_or_expression
%type <ast> logical_and_expression
%type <ast> logical_or_expression
%type <ast> conditional_expression
%type <ast> assignment_expression
%type <ast> assignment_operator
%type <ast> expression
%type <ast> constant_expression
%type <ast> declaration
%type <ast> declaration_specifiers
%type <ast> init_declarator_list
%type <ast> init_declarator
%type <ast> storage_class_specifier
%type <ast> type_specifier
%type <ast> struct_or_union_specifier
%type <ast> struct_or_union
%type <ast> struct_declaration_list
%type <ast> struct_declaration
%type <ast> specifier_qualifier_list
%type <ast> struct_declarator_list
%type <ast> struct_declarator
%type <ast> enum_specifier
%type <ast> enumerator_list
%type <ast> enumerator
%type <ast> type_qualifier
%type <ast> declarator
%type <ast> direct_declarator
%type <ast> pointer
%type <ast> type_qualifier_list
%type <ast> parameter_type_list
%type <ast> parameter_list
%type <ast> parameter_declaration
%type <ast> identifier_list
%type <ast> type_name
%type <ast> abstract_declarator
%type <ast> direct_abstract_declarator
%type <ast> initializer
%type <ast> initializer_list
%type <ast> statement
%type <ast> labeled_statement
%type <ast> compound_statement
%type <ast> declaration_list
%type <ast> statement_list
%type <ast> expression_statement 
%type <ast> selection_statement
%type <ast> iteration_statement
%type <ast> jump_statement
%type <ast> translation_unit 
%type <ast> external_declaration
%type <ast> function_definition

%type <ast> identifier constant string_literal ptr_op inc_op dec_op lparen rparen 
%type <ast> lbracket rbracket point comma sizeof and_sign mul_sign plus_sign tilde 
%type <ast> exclamation_sign minus_sign div_sign percent left_op right_op less_sign
%type <ast> great_sign le_op ge_op eq_op ne_op caret vertical_bar and_op or_op colon
%type <ast> question and_assign mul_assign right_assign div_assign xor_assign mod_assign
%type <ast> or_assign add_assign sub_assign left_assign equal extern typedef register 
%type <ast> auto static signed void float long int short char unsigned struct_type
%type <ast> double lkey rkey struct union semicolon enum const volatile ellipsis case
%type <ast> default if switch else while do for continue break goto return


%start translation_unit

%%

identifier: IDENTIFIER
            {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof(yylval.idname));
               strcpy(temp->text,yylval.idname); //yytext
               temp->value = 300; //symboltable
          //     printf("FOLHA: IDENTIFIER = '%s' %d \n",temp->text,temp->value);
               $$ = temp;
            }
          ;

constant: CONSTANT
            {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("CONSTANT"));
               strcpy(temp->text,"CONSTANT"); //yytext
         //      printf("\n\n\n%d\n\n\n",yylval.type);
               temp->value = yylval.type; //yylval
         //      printf("FOLHA: CONSTANT %d ",temp->value);
               $$ = temp;
            }
          ; 

string_literal: STRING_LITERAL
            {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("STRING_LITERAL"));
               strcpy(temp->text,"STRING_LITERAL"); //yytext
               temp->value = 3; //string_literal
               $$ = temp;
        //       printf("FOLHA: STRING_LITERAL %d ",temp->value);
            }
          ;

ptr_op: PTR_OP
           {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("PTR_OP"));
               strcpy(temp->text,"PTR_OP"); //yytext
               temp->value = 5; //ptr_op
               $$ = temp;
           }
      ;

le_op: LE_OP
           {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("LE_OP"));
               strcpy(temp->text,"GE_OP"); //yytext
               temp->value = 6; //ptr_op
               $$ = temp;
           }
      ;

ge_op: GE_OP
           {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("GE_OP"));
               strcpy(temp->text,"GE_OP"); //yytext
               temp->value = 7; //ptr_op
               $$ = temp;
           }
      ;

eq_op: EQ_OP
           {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("EQ_OP"));
               strcpy(temp->text,"EQ_OP"); //yytext
               temp->value = 8; //ptr_op
               $$ = temp;
           }
      ;

ne_op: NE_OP
           {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("NE_OP"));
               strcpy(temp->text,"NE_OP"); //yytext
               temp->value = 9; //ptr_op
               $$ = temp;
           }
      ;

inc_op: INC_OP
        {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("INC_OP"));
               strcpy(temp->text,"INC_OP"); //yytext
               temp->value = 10; //INC_op
               $$ = temp;
        }
      ; 

dec_op: DEC_OP
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("DEC_OP"));
               strcpy(temp->text,"DEC_OP"); //yytext
               temp->value = 11; //ptr_op
               $$ = temp;
       }
      ; 

left_op: LEFT_OP
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("LEFT_OPP"));
               strcpy(temp->text,"LEFT_OP"); //yytext
               temp->value = 12; //ptr_op
               $$ = temp;
       }
      ; 

right_op: RIGHT_OP
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("RIGHT_OP"));
               strcpy(temp->text,"RIGHT_OP"); //yytext
               temp->value = 13; //ptr_op
               $$ = temp;
       }
      ; 

and_assign: AND_ASSIGN
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("AND_ASSIGN"));
               strcpy(temp->text,"AND_ASSIGN"); //yytext
               temp->value = 14; //ptr_op
               $$ = temp;
       }
      ; 

mul_assign: MUL_ASSIGN
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("MUL_ASSIGN"));
               strcpy(temp->text,"MUL_ASSIGN"); //yytext
               temp->value = 15; //ptr_op
               $$ = temp;
       }
      ; 

right_assign: RIGHT_ASSIGN
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("RIGHT_ASSIGN"));
               strcpy(temp->text,"RIGHT_ASSIGN"); //yytext
               temp->value = 16; //ptr_op
               $$ = temp;
       }
      ; 

div_assign: DIV_ASSIGN
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("DIV_ASSIGN"));
               strcpy(temp->text,"DIV_ASSIGN"); //yytext
               temp->value = 17; //ptr_op
               $$ = temp;
       }
      ; 

xor_assign: XOR_ASSIGN
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("XOR_ASSIGN"));
               strcpy(temp->text,"XOR_ASSIGN"); //yytext
               temp->value = 18; //ptr_op
               $$ = temp;
       }
      ; 

mod_assign: MOD_ASSIGN
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("MOD_ASSIGN"));
               strcpy(temp->text,"MOD_ASSIGN"); //yytext
               temp->value = 19; //ptr_op
               $$ = temp;
       }
      ; 

or_assign: OR_ASSIGN
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("OR_ASSIGN"));
               strcpy(temp->text,"OR_ASSIGN"); //yytext
               temp->value = 20; //ptr_op
               $$ = temp;
       }
      ; 

add_assign: ADD_ASSIGN
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("ADD_ASSIGN"));
               strcpy(temp->text,"ADD_ASSIGN"); //yytext
               temp->value = 21; //ptr_op
               $$ = temp;
       }
      ; 

sub_assign: SUB_ASSIGN
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("SUB_ASSIGN"));
               strcpy(temp->text,"SUB_ASSIGN"); //yytext
               temp->value = 22; //ptr_op
               $$ = temp;
       }
      ; 

left_assign: LEFT_ASSIGN
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("LEFT_ASSIGN"));
               strcpy(temp->text,"LEFT_ASSIGN"); //yytext
               temp->value = 23; //ptr_op
               $$ = temp;
       }
      ; 

sizeof: SIZEOF
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("SIZEOF"));
               strcpy(temp->text,"SIZEOF"); //yytext
               temp->value = 24; //ptr_op
               $$ = temp;
       }
      ; 

and_op: AND_OP
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("AND_OP"));
               strcpy(temp->text,"AND_OP"); //yytext
               temp->value = 25; //ptr_op
               $$ = temp;
       }
      ; 

or_op: OR_OP
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("OR_OP"));
               strcpy(temp->text,"OR_OP"); //yytext
               temp->value = 26; //ptr_op
               $$ = temp;
       }
      ;

extern: EXTERN
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("EXTERN"));
               strcpy(temp->text,"EXTERN"); //yytext
               temp->value = 27; //ptr_op
               $$ = temp;
       }
      ;

typedef: TYPEDEF
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("TYPEDEF"));
               strcpy(temp->text,"TYPEDEF"); //yytext
               temp->value = 28; //ptr_op
               $$ = temp;
       }
      ;

register: REGISTER
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("REGISTER"));
               strcpy(temp->text,"REGISTER"); //yytext
               temp->value = 29; //ptr_op
               $$ = temp;
       }
      ;

auto: AUTO
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("AUTO"));
               strcpy(temp->text,"AUTO"); //yytext
               temp->value = 30; //ptr_op
               $$ = temp;
       }
      ;

static: STATIC
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("STATIC"));
               strcpy(temp->text,"STATIC"); //yytext
               temp->value = 31; //ptr_op
               $$ = temp;
       }
      ;

struct_type: STRUCT_TYPE
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("STRUCT_TYPE"));
               strcpy(temp->text,"STRUCT_TYPE"); //yytext
               temp->value = 32; //ptr_op
               $$ = temp;
       }
      ;

unsigned: UNSIGNED
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("UNSIGNED"));
               strcpy(temp->text,"UNSIGNED"); //yytext
               temp->value = 33; //ptr_op
               $$ = temp;
       }
      ;

char: CHAR
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("CHAR"));
               strcpy(temp->text,"CHAR"); //yytext
               temp->value = 34; //ptr_op
               $$ = temp;
       }
      ;

float: FLOAT
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("FLOAT"));
               strcpy(temp->text,"FLOAT"); //yytext
               temp->value = 35; //ptr_op
               $$ = temp;
       }
      ;

short: SHORT
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("SHORT"));
               strcpy(temp->text,"SHORT"); //yytext
               temp->value = 36; //ptr_op
               $$ = temp;
       }
      ;

void: VOID
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("VOID"));
               strcpy(temp->text,"VOID"); //yytext
               temp->value = 37; //ptr_op
               $$ = temp;
       }
      ;

int: INT
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("INT"));
               strcpy(temp->text,"INT"); //yytext
               temp->value = 38; //ptr_op
              // printf("FOLHA: INT %d \n",temp->value);
               $$ = temp;
       }
      ;

signed: SIGNED
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("SIGNED"));
               strcpy(temp->text,"SIGNED"); //yytext
               temp->value = 39; //ptr_op
               $$ = temp;
       }
      ;

long: LONG
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("LONG"));
               strcpy(temp->text,"LONG"); //yytext
               temp->value = 40; //ptr_op
               $$ = temp;
       }
      ;

double: DOUBLE
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("STATIC"));
               strcpy(temp->text,"STATIC"); //yytext
               temp->value = 41; //ptr_op
               $$ = temp;
       }
      ;

struct: STRUCT
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("STRUCT"));
               strcpy(temp->text,"STRUCT"); //yytext
               temp->value = 42; //ptr_op
               $$ = temp;
       }
      ;

union: UNION
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("UNION"));
               strcpy(temp->text,"UNION"); //yytext
               temp->value = 43; //ptr_op
               $$ = temp;
       }
      ;

enum: ENUM
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("ENUM"));
               strcpy(temp->text,"ENUM"); //yytext
               temp->value = 44; //ptr_op
               $$ = temp;
       }
      ;

const: CONST
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("VOLATILE"));
               strcpy(temp->text,"VOLATILE"); //yytext
               temp->value = 45; //ptr_op
               $$ = temp;
       }
      ;

volatile: VOLATILE
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("VOLATILE"));
               strcpy(temp->text,"VOLATILE"); //yytext
               temp->value = 46; //ptr_op
               $$ = temp;
       }
      ;

ellipsis: ELLIPSIS
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("ELLIPSIS"));
               strcpy(temp->text,"ELLIPSIS"); //yytext
               temp->value = 47; //ptr_op
               $$ = temp;
       }
      ;

default: DEFAULT
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("DEFAULT"));
               strcpy(temp->text,"DEFAULT"); //yytext
               temp->value = 48; //ptr_op
               $$ = temp;
       }
      ;

case: CASE
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("CASE"));
               strcpy(temp->text,"CASE"); //yytext
               temp->value = 49; //ptr_op
               $$ = temp;
       }
      ;

switch: SWITCH
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("SWITCH"));
               strcpy(temp->text,"SWITCH"); //yytext
               temp->value = 50; //ptr_op
               $$ = temp;
       }
      ;

if: IF
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("IF"));
               strcpy(temp->text,"IF"); //yytext
               temp->value = 51; //ptr_op
               $$ = temp;
       }
      ;

else: ELSE
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("ELSE"));
               strcpy(temp->text,"ELSE"); //yytext
               temp->value = 52; //ptr_op
               $$ = temp;
       }
      ;

while: WHILE
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("WHILE"));
               strcpy(temp->text,"WHILE"); //yytext
               temp->value = 53; //ptr_op
               $$ = temp;
       }
      ;

do: DO
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("DO"));
               strcpy(temp->text,"DO"); //yytext
               temp->value = 54; //ptr_op
               $$ = temp;
       }
      ;

for: FOR
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("FOR"));
               strcpy(temp->text,"FOR"); //yytext
               temp->value = 55; //ptr_op
               $$ = temp;
       }
      ;


continue: CONTINUE
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("CONTINUE"));
               strcpy(temp->text,"CONTINUE"); //yytext
               temp->value = 56; //ptr_op
               $$ = temp;
       }
      ;


break: BREAK
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("BREAK"));
               strcpy(temp->text,"BREAK"); //yytext
               temp->value = 57; //ptr_op
               $$ = temp;
       }
      ;


goto: GOTO
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("GOTO"));
               strcpy(temp->text,"GOTO"); //yytext
               temp->value = 58; //ptr_op
               $$ = temp;
       }
      ;


return: RETURN
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("RETURN"));
               strcpy(temp->text,"RETURN"); //yytext
               temp->value = 59; //ptr_op
               $$ = temp;
       }
      ;
lparen: '(' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("("));
               strcpy(temp->text,"("); //yytext
               temp->value = 60; //lparen
               $$ = temp;
       }
;

rparen: ')' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof(")"));
               strcpy(temp->text,")"); //yytext
               temp->value = 61; //lparen
               $$ = temp;
       }
;

lkey: '{' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("{"));
               strcpy(temp->text,"{"); //yytext
               temp->value = 62; //lparen
               $$ = temp;
       }
;

rkey: '}' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("}"));
               strcpy(temp->text,"}"); //yytext
               temp->value = 63; //lparen
               $$ = temp;
       }
;

lbracket: '[' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("["));
               strcpy(temp->text,"["); //yytext
               temp->value = 64; //lparen
               $$ = temp;
       }
;

rbracket: ']' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("]"));
               strcpy(temp->text,"]"); //yytext
               temp->value = 65; //lparen
               $$ = temp;
       }
;

point: '.' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("."));
               strcpy(temp->text,"."); //yytext
               temp->value = 66; //lparen
               $$ = temp;
       }
;

comma: ',' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof(","));
               strcpy(temp->text,","); //yytext
               temp->value = 67; //lparen
               $$ = temp;
       }
;

and_sign: '&' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("&"));
               strcpy(temp->text,"&"); //yytext
               temp->value = 68; //lparen
               $$ = temp;
       }
;

mul_sign: '*' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("*"));
               strcpy(temp->text,"*"); //yytext
               temp->value = 69; //lparen
               $$ = temp;
       }
;

div_sign: '/' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("/"));
               strcpy(temp->text,"/"); //yytext
               temp->value = 70; //lparen
               $$ = temp;
       }
;

plus_sign: '+' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("+"));
               strcpy(temp->text,"+"); //yytext
               temp->value = 71; //lparen
               $$ = temp;
       }
;

minus_sign: '-' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("-"));
               strcpy(temp->text,"-"); //yytext
               temp->value = 72; //lparen
               $$ = temp;
       }
;

less_sign: '<' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("<"));
               strcpy(temp->text,"<"); //yytext
               temp->value = 73; //lparen
               $$ = temp;
       }
;

great_sign: '>' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof(">"));
               strcpy(temp->text,">"); //yytext
               temp->value = 74; //lparen
               $$ = temp;
       }
;

tilde: '~' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("~"));
               strcpy(temp->text,"~"); //yytext
               temp->value = 75; //lparen
               $$ = temp;
       }
;

percent: '%' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("%"));
               strcpy(temp->text,"%"); //yytext
               temp->value = 76; //lparen
               $$ = temp;
       }
;

exclamation_sign: '!' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("!"));
               strcpy(temp->text,"!"); //yytext
               temp->value = 77; //lparen
               $$ = temp;
       }
;

caret: '^' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("^"));
               strcpy(temp->text,"^"); //yytext
               temp->value = 78; //lparen
               $$ = temp;
       }
;

vertical_bar: '|' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("|"));
               strcpy(temp->text,"|"); //yytext
               temp->value = 79; //lparen
               $$ = temp;
       }
;

question: '?' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("?"));
               strcpy(temp->text,"?"); //yytext
               temp->value = 80; //lparen
               $$ = temp;
       }
;

colon: ':' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof(":"));
               strcpy(temp->text,":"); //yytext
               temp->value = 81; //lparen
               $$ = temp;
       }
;

semicolon: ';' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof(":"));
               strcpy(temp->text,";"); //yytext
               temp->value = 82; //lparen
           //    printf("FOLHA: ; %d \n",temp->value);
               $$ = temp;
       }
;

equal: '=' 
       {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof(":"));
               strcpy(temp->text,"="); //yytext
               temp->value = 83; //lparen
               $$ = temp;
       }
;


translation_unit 
	: external_declaration 
              {
                    ast = new Ast();
                    ast->a = $1;
                    ast->value = 84;
                 //   printf("translation_unit: external_declaration %d \n",ast->value);
                    $$ = ast;                
              }
	| translation_unit external_declaration 
              {
                    ast = new Ast();
                    ast->a = $1;
                    ast->b = $2;
                    ast->value = 85;
               //     printf("translation_unit: translation_unit external_declaration %d \n",ast->value);
                    $$ = ast;      
              }
	;

primary_expression
	: identifier
              {/* printf("IDENTIFIER |"); */
                    PrimaryExpression *temp = new PrimaryExpression();
                    temp->a = $1;
                    temp->value = 86;
                    $$ = temp;     
              }
	| constant
              {/* printf(" CONSTANT |"); */
                    PrimaryExpression *temp = new PrimaryExpression();
                    temp->a = $1;
                    temp->value = 87;
                    $$ = temp;     
              }
	| string_literal 
              {/* printf(" STRING_LITERAL |"); */
                    PrimaryExpression *temp = new PrimaryExpression();
                    temp->a = $1;
                    temp->value = 88;
                    $$ = temp;     
              }
	| lparen expression rparen 
              {/* printf(" '(' expression ')' | "); */
                    PrimaryExpression *temp = new PrimaryExpression();
                    temp->a = $1;
                    temp->b = $2;
                    temp->c = $3;
                    temp->value = 89;
                    $$ = temp;     
              } 
	;

postfix_expression
	: primary_expression 
              {
                  PostfixExpression *temp = new PostfixExpression();
                  temp->a = $1;
                  temp->value = 90;
                    $$ = temp;     
              }
	| postfix_expression lbracket expression rbracket 
              {
                  PostfixExpression *temp = new PostfixExpression();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->value = 91;
                    $$ = temp;     
              }
	| postfix_expression lparen rparen 
              {/* printf("postfix_expression '(' ')' |"); */
                  PostfixExpression *temp = new PostfixExpression();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 92;
                    $$ = temp;     
              }
	| postfix_expression lparen argument_expression_list rparen 
              {/* printf("postfix_expression '(' argument_expression_list ')'  |"); */
                  PostfixExpression *temp = new PostfixExpression();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->value = 93;
                    $$ = temp;     
              }
	| postfix_expression point identifier
              {/* printf("postfix_expression '.' IDENTIFIER |"); */
                  PostfixExpression *temp = new PostfixExpression();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 94;
                    $$ = temp;     
              }
	| postfix_expression ptr_op identifier
              {/* printf("postfix_expression PTR_OP IDENTIFIER  |"); */
                  PostfixExpression *temp = new PostfixExpression();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3; 
                  temp->value = 95;
                    $$ = temp;     
              }
	| postfix_expression inc_op 
              {/* printf("postfix_expression INC_OP |"); */
                  PostfixExpression *temp = new PostfixExpression();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 96;
                    $$ = temp;     
              }
	| postfix_expression dec_op
              {/* printf("postfix_expression DEC_OP |"); */
                  PostfixExpression *temp = new PostfixExpression();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 97;
                    $$ = temp;     
              }
	;

argument_expression_list
	: assignment_expression 
              {/* printf("assignment_expression |"); */
                 ArgumentExpressionList *temp = new ArgumentExpressionList();
                 temp->a = $1;
                 temp->value = 98;
                    $$ = temp;     
              }
	| argument_expression_list comma assignment_expression 
              {/* printf("argument_expression_list ',' assignment_expression |"); */
                 ArgumentExpressionList *temp = new ArgumentExpressionList();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3; 
                 temp->value = 99;
                    $$ = temp;     
              }
	; 

unary_expression
	: postfix_expression 
              {/* printf(" |"); */
               UnaryExpression *temp = new UnaryExpression();
               temp->a = $1;
               temp->value = 100;
                    $$ = temp;     
              }
	| inc_op unary_expression 
              {/* printf(" |"); */
               UnaryExpression *temp = new UnaryExpression();
               temp->a = $1;
               temp->b = $2;
               temp->value = 101;
                    $$ = temp;     
              }
	| dec_op unary_expression 
              {/* printf(" |"); */
               UnaryExpression *temp = new UnaryExpression();
               temp->a = $1;
               temp->b = $2;
               temp->value = 102;
                    $$ = temp;     
              }
	| unary_operator cast_expression
              {/* printf(" |"); */
               UnaryExpression *temp = new UnaryExpression();
               temp->a = $1;
               temp->b = $2;
               temp->value = 103;
                    $$ = temp;     
              }
	| sizeof unary_expression 
              {/* printf(" |"); */
               UnaryExpression *temp = new UnaryExpression();
               temp->a = $1;
               temp->b = $2;
               temp->value = 104;
                    $$ = temp;     
              }
	| sizeof lparen type_name rparen 
              {/* printf(" |"); */
               UnaryExpression *temp = new UnaryExpression();
               temp->a = $1;
               temp->b = $2;
               temp->c = $3;
               temp->d = $4;
               temp->value = 105;
                    $$ = temp;     
              }
	;

unary_operator
	: and_sign
              {/* printf(" |"); */
               UnaryOperator *temp = new UnaryOperator();
               temp->a = $1;
               temp->value = 106;
                    $$ = temp;     
              }
	| mul_sign
              {/* printf(" |"); */
               UnaryOperator *temp = new UnaryOperator();
               temp->a = $1;
               temp->value = 107;
                    $$ = temp;     
              }
	| plus_sign
              {/* printf(" |"); */
               UnaryOperator *temp = new UnaryOperator();
               temp->a = $1;
               temp->value = 108;
                    $$ = temp;     
              }
	| minus_sign
              {/* printf(" |"); */
               UnaryOperator *temp = new UnaryOperator();
               temp->a = $1;
               temp->value = 109;
                    $$ = temp;     
              }
	| tilde
              {/* printf(" |"); */
               UnaryOperator *temp = new UnaryOperator();
               temp->a = $1;
               temp->value = 110;
                    $$ = temp;     
              }
	| exclamation_sign
              {/* printf(" |"); */
               UnaryOperator *temp = new UnaryOperator();
               temp->a = $1;
               temp->value = 111;
                    $$ = temp;     
              }
	;

cast_expression
	: unary_expression 
              {/* printf(" |"); */
               CastExpression *temp = new CastExpression();
               temp->a = $1;
               temp->value = 112;
                    $$ = temp;     
              }
	| lparen type_name rparen cast_expression 
              {/* printf(" |"); */
               CastExpression *temp = new CastExpression();
               temp->a = $1;
               temp->b = $2;
               temp->c = $3;
               temp->d = $4;
               temp->value = 113;
                    $$ = temp;     
              }
	;

multiplicative_expression
	: cast_expression 
              {/* printf(" |"); */
               MultiplicativeExpression *temp = new MultiplicativeExpression();
               temp->a = $1;
               temp->value = 114;
                    $$ = temp;     
              }
	| multiplicative_expression mul_sign cast_expression 
              {/* printf(" |"); */
               MultiplicativeExpression *temp = new MultiplicativeExpression();
               temp->a = $1;
               temp->b = $2;
               temp->c = $3;
               temp->value = 115;
                    $$ = temp;     
              }
	| multiplicative_expression div_sign cast_expression
              {/* printf(" |"); */
               MultiplicativeExpression *temp = new MultiplicativeExpression();
               temp->a = $1;
               temp->b = $2;
               temp->c = $3;
               temp->value = 116;
                    $$ = temp;     
              }
	| multiplicative_expression percent cast_expression 
              {/* printf(" |"); */
               MultiplicativeExpression *temp = new MultiplicativeExpression();
               temp->a = $1;
               temp->b = $2;
               temp->c = $3;
               temp->value = 117;
                    $$ = temp;     
              }
	;

additive_expression
	: multiplicative_expression 
              {/* printf(" |"); */
                  AdditiveExpression *temp = new AdditiveExpression();
                  temp->a = $1;
                  temp->value = 118;
                    $$ = temp;     
              }
	| additive_expression plus_sign multiplicative_expression 
              {/* printf(" |"); */
                  AdditiveExpression *temp = new AdditiveExpression();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 119;
                    $$ = temp;     
              }
	| additive_expression minus_sign multiplicative_expression 
              {/* printf(" |"); */
                  AdditiveExpression *temp = new AdditiveExpression();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 120;
                    $$ = temp;     
              }
	;

shift_expression
	: additive_expression 
              {/* printf(" |"); */
                 ShiftExpression *temp = new ShiftExpression();
                 temp->a = $1;
                 temp->value = 121;
                    $$ = temp;     
              }
	| shift_expression left_op additive_expression 
              {/* printf(" |"); */
                 ShiftExpression *temp = new ShiftExpression();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 122;
                    $$ = temp;     
              }
	| shift_expression right_op additive_expression 
              {/* printf(" |"); */
                 ShiftExpression *temp = new ShiftExpression();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 123;
                    $$ = temp;     
              }
	;

relational_expression
	: shift_expression 
              {/* printf(" |"); */
                 RelationalExpression *temp = new RelationalExpression();
                 temp->a = $1;
                 temp->value = 124;
                    $$ = temp;     
              }
	| relational_expression less_sign shift_expression 
              {/* printf(" |"); */
                 RelationalExpression *temp = new RelationalExpression();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 125;
                    $$ = temp;     
              }
	| relational_expression great_sign shift_expression 
              {/* printf(" |"); */
                 RelationalExpression *temp = new RelationalExpression();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 126;
                    $$ = temp;     
              }
	| relational_expression le_op shift_expression 
              {/* printf(" |"); */
                 RelationalExpression *temp = new RelationalExpression();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 127;
                    $$ = temp;     
              }
	| relational_expression ge_op shift_expression 
              {/* printf(" |"); */
                 RelationalExpression *temp = new RelationalExpression();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 128;
                    $$ = temp;     
              }
	;

equality_expression
	: relational_expression
              {
                 EqualityExpression *temp = new EqualityExpression();
                 temp->a = $1;
                 temp->value = 129;
                    $$ = temp;     
              }
	| equality_expression eq_op relational_expression 
              {/* printf(" |"); */
                 EqualityExpression *temp = new EqualityExpression();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 130;
                    $$ = temp;     
              }
	| equality_expression ne_op relational_expression 
              {/* printf(" |"); */
                 EqualityExpression *temp = new EqualityExpression();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 131;
                    $$ = temp;     
              }
	;

and_expression
	: equality_expression 
              {/* printf(" |"); */
                 AndExpression *temp = new AndExpression();
                 temp->a = $1;
                 temp->value = 132;
                    $$ = temp;     
              }
	| and_expression and_sign equality_expression 
              {/* printf(" |"); */
                 AndExpression *temp = new AndExpression();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 133;
                    $$ = temp;     
              }
	;

exclusive_or_expression
	: and_expression 
              {/* printf(" |"); */
                 ExclusiveOrExpression *temp = new ExclusiveOrExpression();
                 temp->a = $1;
                 temp->value = 134;
                    $$ = temp;     
              }
	| exclusive_or_expression caret and_expression 
              {/* printf(" |"); */
                 ExclusiveOrExpression *temp = new ExclusiveOrExpression();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 135;
                    $$ = temp;     
              }
	;

inclusive_or_expression
	: exclusive_or_expression 
            {/* printf(" |"); */
                 InclusiveOrExpression *temp = new InclusiveOrExpression();
                 temp->a = $1;
                 temp->value = 136;
                    $$ = temp;     
            }
	| inclusive_or_expression vertical_bar exclusive_or_expression 
            {/* printf(" |"); */
                 InclusiveOrExpression *temp = new InclusiveOrExpression();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 137;
                    $$ = temp;     
            }
	;

logical_and_expression
	: inclusive_or_expression 
            {/* printf(" |"); */
                 LogicalAndExpression *temp = new LogicalAndExpression();
                 temp->a = $1;
                 temp->value = 138;
                    $$ = temp;     
            }
	| logical_and_expression and_op inclusive_or_expression 
            {/* printf(" |"); */
                 LogicalAndExpression *temp = new LogicalAndExpression();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 139;
                    $$ = temp;     
            }
	;

logical_or_expression
	: logical_and_expression 
            {/* printf(" |"); */
                 LogicalOrExpression *temp = new LogicalOrExpression();
                 temp->a = $1;
                 temp->value = 140;
                    $$ = temp;     
            }
	| logical_or_expression or_op logical_and_expression 
            {/* printf(" |"); */
                 LogicalOrExpression *temp = new LogicalOrExpression();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 141;
                    $$ = temp;     
            }
	;

conditional_expression
	: logical_or_expression 
            {/* printf(" |"); */
                 ConditionalExpression *temp = new ConditionalExpression();
                 temp->a = $1;
                 temp->value = 142;
                    $$ = temp;     
            }
	| logical_or_expression question expression colon conditional_expression 
            {/* printf(" |"); */
                 ConditionalExpression *temp = new ConditionalExpression();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->d = $4;
                 temp->e = $5;
                 temp->value = 143;
                    $$ = temp;     
            }
	;

assignment_expression
	: conditional_expression 
            {/* printf(" |"); */
                 AssignmentExpression *temp = new AssignmentExpression();
                 temp->a = $1;
                 temp->value = 144;
                    $$ = temp;     
            }
	| unary_expression assignment_operator assignment_expression 
            {/* printf(" |"); */
                 AssignmentExpression *temp = new AssignmentExpression();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 145;
                    $$ = temp;     
            }
	;

assignment_operator
	: equal 
            {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = $1;
                 temp->value = 146;
                    $$ = temp;     
            }
	| mul_assign 
            {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = $1;
                 temp->value = 147;
                    $$ = temp;     
            }
	| div_assign 
            {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = $1;
                 temp->value = 148;
                    $$ = temp;     
            }
	| mod_assign 
            {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = $1;
                 temp->value = 149;
                    $$ = temp;     
            }
	| add_assign 
            {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = $1;
                 temp->value = 150;
                    $$ = temp;     
            }
	| sub_assign 
            {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = $1;
                 temp->value = 151;
                    $$ = temp;     
            }
	| left_assign 
            {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = $1;
                 temp->value = 152;
                    $$ = temp;     
            }
	| right_assign 
            {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = $1;
                 temp->value = 153;
                    $$ = temp;     
            }
	| and_assign 
            {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = $1;
                 temp->value = 154;
                    $$ = temp;     
            }
	| xor_assign 
            {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = $1;
                 temp->value = 155;
                    $$ = temp;     
            }
	| or_assign 
            {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = $1;
                 temp->value = 156;
                    $$ = temp;     
            }
	;

expression
	: assignment_expression 
              {/* printf(" |"); */
                 Expression *temp = new Expression();
                 temp->a = $1;
                 temp->value = 157;
                    $$ = temp;     
              }
	| expression comma assignment_expression 
              {/* printf(" |"); */
                 Expression *temp = new Expression();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 158;
                    $$ = temp;     
              }
	;

constant_expression
	: conditional_expression 
              {/* printf(" |"); */
                 ConstantExpression *temp = new ConstantExpression();
                 temp->a = $1;
                 temp->value = 159;
                    $$ = temp;     
              }
	;

declaration
	: declaration_specifiers semicolon 
              {/* printf ("declaration_specifiers ; | "); */
                 Declaration *temp = new Declaration();
                 temp->a = $1;
                 temp->b = $2;
                 temp->value = 160;
                // printf("declaration: declaration_specifiers semicolon %d \n",temp->value);
                    $$ = temp;     
              }
	| declaration_specifiers init_declarator_list semicolon 
              {
                 Declaration *temp = new Declaration();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 161;
                // printf("declaration: declaration_specifiers init_declarator_list semicolon %d \n",temp->value);
                 $$ = temp;     
              }
	;

declaration_specifiers
	: storage_class_specifier 
              {
                 DeclarationSpecifiers *temp = new DeclarationSpecifiers();
                 temp->a = $1;
                 temp->value = 162;
                    $$ = temp;     
              }
	| storage_class_specifier declaration_specifiers 
              {
                 DeclarationSpecifiers *temp = new DeclarationSpecifiers();
                 temp->a = $1;
                 temp->b = $2;
                 temp->value = 163;
                    $$ = temp;     
              }
	| type_specifier 
              {
                 DeclarationSpecifiers *temp = new DeclarationSpecifiers();
                 temp->a = $1;
                 temp->value = 164;
               //  printf("DeclarationSpecifier: type_specifier %d \n",temp->value);
                    $$ = temp;     
              }
	| type_specifier declaration_specifiers 
              {
                 DeclarationSpecifiers *temp = new DeclarationSpecifiers();
                 temp->a = $1;
                 temp->b = $2;
                 temp->value = 165;
                    $$ = temp;     
              }
	| type_qualifier 
              {/* printf ("type_qualifier | "); */
                 DeclarationSpecifiers *temp = new DeclarationSpecifiers();
                 temp->a = $1;
                 temp->value = 166;
                    $$ = temp;     
              }
	| type_qualifier declaration_specifiers 
              {/* printf ("type_qualifier declaration_specifiers | "); */
                 DeclarationSpecifiers *temp = new DeclarationSpecifiers();
                 temp->a = $1;
                 temp->b = $2;
                 temp->value = 167;
                    $$ = temp;     
              }
	;

init_declarator_list
	: init_declarator 
              {
                 InitDeclaratorList *temp = new InitDeclaratorList();
                 temp->a = $1;
                 temp->value = 168;
               //  printf("InitDeclaratorList: init_declarator %d \n",temp->value);
                 $$ = temp;     
              }
	| init_declarator_list comma init_declarator 
              {
                 InitDeclaratorList *temp = new InitDeclaratorList();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 169;
                 $$ = temp;     
              }
	;

init_declarator
	: declarator 
              {
                 InitDeclarator *temp = new InitDeclarator();
                 temp->a = $1;
                 temp->value = 170;
               //  printf("InitDeclarator: declarator %d \n",temp->value);
                 $$ = temp;     
              }
	| declarator equal initializer 
              {
                 InitDeclarator *temp = new InitDeclarator();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 171;
                    $$ = temp;     
              }
	;

storage_class_specifier
	: typedef 
              {/* printf(" |"); */
                 StorageClassSpecifier *temp = new StorageClassSpecifier();
                 temp->a = $1;
                 temp->value = 172;
                    $$ = temp;     
              }
	| extern 
              {/* printf(" |"); */
                 StorageClassSpecifier *temp = new StorageClassSpecifier();
                 temp->a = $1;
                 temp->value = 173;
                    $$ = temp;     
              }
	| static
              {/* printf(" |"); */
                 StorageClassSpecifier *temp = new StorageClassSpecifier();
                 temp->a = $1;
                 temp->value = 174;
                    $$ = temp;     
              }
	| auto 
              {/* printf(" |"); */
                 StorageClassSpecifier *temp = new StorageClassSpecifier();
                 temp->a = $1;
                 temp->value = 175;
                    $$ = temp;     
              }
	| register 
              {/* printf(" |"); */
                 StorageClassSpecifier *temp = new StorageClassSpecifier();
                 temp->a = $1;
                 temp->value = 176;
                    $$ = temp;     
              }
	;

type_specifier
	: void 
              {/* printf ("VOID | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = $1;
                 temp->value = 177;
                    $$ = temp;     
              }
	| char 
              {/* printf ("CHAR  | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = $1;
                 temp->value = 178;
                    $$ = temp;     
              }
	| short 
              {/* printf ("SHORT | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = $1;
                 temp->value = 179;
                    $$ = temp;     
              }
	| int
              {/* printf ("INT| "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = $1;
                 temp->value = 180;
              //   printf("typeSpecifier: int %d \n",temp->value);
                    $$ = temp;     
              }
	| long 
              {/* printf ("LONG | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = $1;
                 temp->value = 181;
                    $$ = temp;     
              }
	| float 
              {/* printf ("FLOAT | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = $1;
                 temp->value = 182;
                    $$ = temp;     
              }
	| double 
              {/* printf ("DOUBLE | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = $1;
                 temp->value = 183;
                    $$ = temp;     
              }
	| signed 
              {/* printf ("SIGNED | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = $1;
                 temp->value = 184;
                    $$ = temp;     
              }
	| unsigned 
              {/* printf ("UNSIGNED  | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = $1;
                 temp->value = 185;
                    $$ = temp;     
              }
	| struct_or_union_specifier 
              {/* printf ("struct_or_union_specifier | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = $1;
                 temp->value = 186;
                    $$ = temp;     
              }
	| enum_specifier 
              {/* printf ("enum_specifier | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = $1;
                 temp->value = 187;
                    $$ = temp;     
              }
            | struct_type     
              {  //printf("não entendi"); 
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = $1;
                 temp->value = 188;
                    $$ = temp;     
              }
	;//sumi com o type_name e deu bug 2 meses depois huahuaehuae

struct_or_union_specifier
	: struct_or_union identifier lkey struct_declaration_list rkey  
              {/* printf ("struct_or_union IDENTIFIER { struct_declaration_list }  | "); */
                 StructOrUnionSpecifier *temp = new StructOrUnionSpecifier();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->d = $4;
                 temp->e = $5;
                 temp->value = 189;
                    $$ = temp;     
              }
	| struct_or_union lkey struct_declaration_list rkey 
              {
                 StructOrUnionSpecifier *temp = new StructOrUnionSpecifier();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->d = $4;
                 temp->value = 190;
                    $$ = temp;     
              }
	| struct_or_union identifier  
              {/* printf ("struct_or_union IDENTIFIER | "); */
                 StructOrUnionSpecifier *temp = new StructOrUnionSpecifier();
                 temp->a = $1;
                 temp->b = $2;
                 temp->value = 191;
                    $$ = temp;     
              }
	;

struct_or_union
	: struct
              {/* printf ("STRUCT | "); */
                 StructOrUnion *temp = new StructOrUnion();
                 temp->a = $1;
                 temp->value = 192;
                    $$ = temp;     
              }
	| union
              {/* printf ("UNION | "); */
                 StructOrUnion *temp = new StructOrUnion();
                 temp->a = $1;
                 temp->value = 193;
                    $$ = temp;     
              }
	;

struct_declaration_list
	: struct_declaration 
              {/* printf ("struct_declaration | "); */
                 StructDeclarationList *temp = new StructDeclarationList();
                 temp->a = $1;
                 temp->value = 194;
                    $$ = temp;     
              }
	| struct_declaration_list struct_declaration 
              {/* printf ("struct_declaration_list struct_declaration| "); */
                 StructDeclarationList *temp = new StructDeclarationList();
                 temp->a = $1;
                 temp->b = $2;
                 temp->value = 195;
                    $$ = temp;     
              }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list semicolon 
              {
                 StructOrUnionSpecifier *temp = new StructOrUnionSpecifier();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 196;
                    $$ = temp;     
              }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list 
              {/* printf ("type_specifier specifier_qualifier_list | "); */
                 SpecifierQualifierList *temp = new SpecifierQualifierList();
                 temp->a = $1;
                 temp->b = $2;
                 temp->value = 197;
                    $$ = temp;     
              }
	| type_specifier 
              {/* printf ("type_specifier  | "); */
                 SpecifierQualifierList *temp = new SpecifierQualifierList();
                 temp->a = $1;
                 temp->value = 198;
                    $$ = temp;     
              }
	| type_qualifier specifier_qualifier_list 
              {/* printf ("type_qualifier specifier_qualifier_list | "); */
                 SpecifierQualifierList *temp = new SpecifierQualifierList();
                 temp->a = $1;
                 temp->b = $2;
                 temp->value = 199;
                    $$ = temp;     
              }
	| type_qualifier 
              {/* printf ("type_qualifier | "); */
                 SpecifierQualifierList *temp = new SpecifierQualifierList();
                 temp->a = $1;
                 temp->value = 200;
                    $$ = temp;     
              }
	;

struct_declarator_list
	: struct_declarator 
              {/* printf ("struct_declarator | "); */
                 StructDeclaratorList *temp = new StructDeclaratorList();
                 temp->a = $1;
                 temp->value = 201;
                    $$ = temp;     
              }
	| struct_declarator_list comma struct_declarator
              {/* printf ("struct_declarator_list ',' struct_declarator  | "); */
                 StructDeclaratorList *temp = new StructDeclaratorList();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 202;
                    $$ = temp;     
              }
	;

struct_declarator
	: declarator 
              {/* printf ("declarator | "); */
                 StructDeclarator *temp = new StructDeclarator();
                 temp->a = $1;
                 temp->value = 203;
                    $$ = temp;     
              }
	| colon constant_expression 
              {/* printf ("':' constant_expression | "); */
                 StructDeclarator *temp = new StructDeclarator();
                 temp->a = $1;
                 temp->b = $2;
                 temp->value = 204;
                    $$ = temp;     
              }
	| declarator colon constant_expression 
              {/* printf ("declarator ':' constant_expression | "); */
                 StructDeclarator *temp = new StructDeclarator();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 205;
                    $$ = temp;     
              }
	;

enum_specifier
	: enum lkey enumerator_list rkey 
              {/* printf(" |"); */
                 EnumSpecifier *temp = new EnumSpecifier();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->d = $4;
                 temp->value = 206;
                    $$ = temp;     
              }
	| enum identifier lkey enumerator_list rkey 
              {/* printf(" |"); */
                 EnumSpecifier *temp = new EnumSpecifier();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->d = $4;
                 temp->e = $5;
                 temp->value = 207;
                    $$ = temp;     
              }
	| enum identifier 
              {/* printf(" |"); */
                 EnumSpecifier *temp = new EnumSpecifier();
                 temp->a = $1;
                 temp->b = $2;
                 temp->value = 208;
                    $$ = temp;     
              }
	;

enumerator_list
	: enumerator 
              {/* printf(" |"); */
                 EnumeratorList *temp = new EnumeratorList();
                 temp->a = $1;
                 temp->value = 209;
                    $$ = temp;     
              }
	| enumerator_list comma enumerator 
              {/* printf(" |"); */
                 EnumeratorList *temp = new EnumeratorList();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 210;
                    $$ = temp;     
              }
	;

enumerator
	: identifier
              {/* printf(" |"); */
                 Enumerator *temp = new Enumerator();
                 temp->a = $1;
                 temp->value = 211;
                    $$ = temp;     
              }
	| identifier equal constant_expression 
              {/* printf(" |"); */
                 Enumerator *temp = new Enumerator();
                 temp->a = $1;
                 temp->b = $2;
                 temp->c = $3;
                 temp->value = 212;
                    $$ = temp;     
              }
	;

type_qualifier
	: const
              {/* printf("CONST |"); */
                 TypeQualifier *temp = new TypeQualifier();
                 temp->a = $1;
                 temp->value = 213;
                    $$ = temp;     
              }
	| volatile 
              {/* printf("VOLATILE  |"); */
                 TypeQualifier *temp = new TypeQualifier();
                 temp->a = $1;
                 temp->value = 214;
                    $$ = temp;     
              }
	;

declarator
	: pointer direct_declarator 
              {/* printf("pointer direct_declarator |"); */
                 Declarator *temp = new Declarator();
                 temp->a = $1;
                 temp->b = $2;
                 temp->value = 215;
                    $$ = temp;                       
              }
	| direct_declarator 
              {/* printf("direct_declarator |"); */
                 Declarator *temp = new Declarator();
                 temp->a = $1;
                 temp->value = 216;
               //  printf("Declarator: direct_declarator %d \n",temp->value);
                 $$ = temp;                       
              }
	;

direct_declarator
	: identifier
              {/* printf("IDENTIFIER |"); */
                  DirectDeclarator *temp = new DirectDeclarator();
                  temp->a = $1;
                  temp->value = 217;
                //  printf("DirectDeclarator: identifier %d \n",temp->value);
                    $$ = temp;     
              }
	| '(' declarator rparen
              {/* printf("'(' declarator ')' |"); */ //GAMBS se algum dia bugar eh aqui
                  DirectDeclarator *temp = new DirectDeclarator();

                  temp->a = new Folha();
                  temp->a->text = (char *) malloc(sizeof("("));
                  strcpy(temp->a->text,"("); //yytext
                  temp->a->value = 0; //lparen
 
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 218;
                    $$ = temp;     

              }
	| direct_declarator lbracket constant_expression rbracket 
              {/* printf("direct_declarator '[' constant_expression ']' |"); */
                  DirectDeclarator *temp = new DirectDeclarator();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->value = 219;
                    $$ = temp;     
              }
	| direct_declarator lbracket rbracket 
              {/* printf("direct_declarator '[' ']' |"); */
                  DirectDeclarator *temp = new DirectDeclarator();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 220;
                    $$ = temp;     
              }
	| direct_declarator lparen parameter_type_list rparen 
              {/* printf("direct_declarator '(' parameter_type_list ')' |"); */
                  DirectDeclarator *temp = new DirectDeclarator();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->value = 221;
                    $$ = temp;     
              }
	| direct_declarator lparen identifier_list rparen
              {/* printf("direct_declarator '(' identifier_list ')' |"); */
                  DirectDeclarator *temp = new DirectDeclarator();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->value = 222;
                    $$ = temp;     
              }
	| direct_declarator lparen rparen 
              {/* printf("direct_declarator '(' ')' |"); */
                  DirectDeclarator *temp = new DirectDeclarator();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 223;
                    $$ = temp;     
              }
	;

pointer
	: mul_sign 
             {/* printf(" |"); */
                  Pointer *temp = new Pointer();
                  temp->a = $1;
                  temp->value = 224;
                    $$ = temp;     
             }
	| mul_sign type_qualifier_list 
             {/* printf(" |"); */
                  Pointer *temp = new Pointer();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 225;
                    $$ = temp;     
             }
	| mul_sign pointer 
             {/* printf(" |"); */
                  Pointer *temp = new Pointer();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 226;
                    $$ = temp;     
             }
	| mul_sign type_qualifier_list pointer 
             {/* printf(" |"); */
                  Pointer *temp = new Pointer();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 227;
                    $$ = temp;     
             }
	;

type_qualifier_list
	: type_qualifier 
              {/* printf("type_qualifier |"); */
                  TypeQualifierList *temp = new TypeQualifierList();
                  temp->a = $1;
                  temp->value = 228;
                    $$ = temp;     
              }
	| type_qualifier_list type_qualifier 
              {/* printf("type_qualifier_list type_qualifier |"); */
                  TypeQualifierList *temp = new TypeQualifierList();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 229;
                    $$ = temp;     
              }
	;


parameter_type_list
	: parameter_list 
              {/* printf("parameter_list |"); */
                  ParameterTypeList *temp = new ParameterTypeList();
                  temp->a = $1;
                  temp->value = 230;
                    $$ = temp;     
              }
	| parameter_list semicolon ellipsis 
              {/* printf("parameter_list ',' ELLIPSIS |"); */
                  ParameterTypeList *temp = new ParameterTypeList();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 231;
                    $$ = temp;     
              }
	;

parameter_list
	: parameter_declaration 
              {/* printf("parameter_declaration |"); */
                  ParameterList *temp = new ParameterList();
                  temp->a = $1;
                  temp->value = 232;
                    $$ = temp;     
              }
	| parameter_list comma parameter_declaration 
              {/* printf("parameter_list ',' parameter_declaration |"); */
                  ParameterList *temp = new ParameterList();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 233;
                    $$ = temp;     
              }
	;

parameter_declaration
	: declaration_specifiers declarator 
              {
                  ParameterDeclaration *temp = new ParameterDeclaration();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 234;
                    $$ = temp;     
              }
	| declaration_specifiers abstract_declarator 
              {
                  ParameterDeclaration *temp = new ParameterDeclaration();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 235;
                    $$ = temp;     
              }
	| declaration_specifiers 
              {
                  ParameterDeclaration *temp = new ParameterDeclaration();
                  temp->a = $1;
                  temp->value = 236;
                    $$ = temp;     
              }
	;

identifier_list
	: identifier
              {/* printf("IDENTIFIER  |"); */
                  IdentifierList *temp = new IdentifierList();
                  temp->a = $1;
                  temp->value = 237;
                    $$ = temp;     
              }
	| identifier_list comma identifier 
              {/* printf("identifier_list ',' IDENTIFIER  |"); */
                  IdentifierList *temp = new IdentifierList();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 238;
                    $$ = temp;     
              }
	;

type_name
	: specifier_qualifier_list 
              {/* printf("specifier_qualifier_list  |"); */
                  TypeName *temp = new TypeName();
                  temp->a = $1;
                  temp->value = 239;
                    $$ = temp;     
              }
	| specifier_qualifier_list abstract_declarator 
              {/* printf("specifier_qualifier_list abstract_declarator |"); */
                  TypeName *temp = new TypeName();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 240;
                    $$ = temp;     
              }
	;


abstract_declarator
	: pointer 
              {/* printf(" |"); */
                  AbstractDeclarator *temp = new AbstractDeclarator();
                  temp->a = $1;
                  temp->value = 241;
                    $$ = temp;     
              }
	| direct_abstract_declarator 
              {/* printf(" |"); */
                  AbstractDeclarator *temp = new AbstractDeclarator();
                  temp->a = $1;
                  temp->value = 242;
                    $$ = temp;     
              }
	| pointer direct_abstract_declarator 
              {/* printf(" |"); */
                  AbstractDeclarator *temp = new AbstractDeclarator();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 243;
                    $$ = temp;     
              }
	;

direct_abstract_declarator
	: '(' abstract_declarator rparen
              {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();

                  temp->a = new Folha();
                  temp->a->text = (char *) malloc(sizeof("("));
                  strcpy(temp->a->text,"("); //yytext
                  temp->a->value = 0; //lparen
 
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 244;
                    $$ = temp;     
              }
	| lbracket rbracket 
              {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 245;
                    $$ = temp;     
              }
	| lbracket constant_expression rbracket 
              {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 246;
                    $$ = temp;     
              }
	| direct_abstract_declarator lbracket rbracket 
              {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 247;
                    $$ = temp;     
              }
	| direct_abstract_declarator lbracket constant_expression rbracket 
              {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->value = 248;
                    $$ = temp;     
              }
	| lparen rparen
              {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 249;
                    $$ = temp;     
              }
	| lparen parameter_type_list rparen 
              {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 250;
                    $$ = temp;     
              }
	| direct_abstract_declarator lparen rparen 
              {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 251;
                    $$ = temp;     
              }
	| direct_abstract_declarator lparen parameter_type_list rparen 
              {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->value = 252;
                    $$ = temp;     
              }
	;

initializer
	: assignment_expression 
              {/* printf("assignment_expression |"); */
                  Initializer *temp = new Initializer();
                  temp->a = $1;
                  temp->value = 253;
                    $$ = temp;     
              }
	| lkey initializer_list rkey 
              {
                  Initializer *temp = new Initializer();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 254;
                    $$ = temp;     
              }
	| lkey initializer_list comma rkey 
              {
                  Initializer *temp = new Initializer();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->value = 255;
                    $$ = temp;     
              }
	;

initializer_list
	: initializer 
              {/* printf("initializer |"); */
                  InitializerList *temp = new InitializerList();
                  temp->a = $1;
                  temp->value = 256;
                    $$ = temp;                    
              }
	| initializer_list comma initializer 
              {/* printf("initializer_list ',' initializer |"); */
                  InitializerList *temp = new InitializerList();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 257;
                    $$ = temp;        
              }
	;

statement
	: labeled_statement 
              {/* printf("labeled_statement |"); */
                  Statement *temp = new Statement();
                  temp->a = $1;
                  temp->value = 258;
                    $$ = temp;      
              }
	| compound_statement 
              {/* printf("compound_statement |"); */
                  Statement *temp = new Statement();
                  temp->a = $1;
                  temp->value = 259;
                    $$ = temp;      
              }
	| expression_statement 
              {/* printf("expression_statement |"); */
                  Statement *temp = new Statement();
                  temp->a = $1;
                  temp->value = 260;
                    $$ = temp;      
              }
	| selection_statement 
              {/* printf("selection_statement |"); */
                  Statement *temp = new Statement();
                  temp->a = $1;
                  temp->value = 261;
                    $$ = temp;      
              }
	| iteration_statement 
              {/* printf("iteration_statement |"); */
                  Statement *temp = new Statement();
                  temp->a = $1;
                  temp->value = 262;
                    $$ = temp;      
              }
	| jump_statement 
              {/* printf("jump_statement |"); */
                  Statement *temp = new Statement();
                  temp->a = $1;
                  temp->value = 263;
                    $$ = temp;      
              }
	;

labeled_statement
	: identifier colon statement 
              {/* printf(" |"); */
                  LabeledStatement *temp = new LabeledStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 264;
                    $$ = temp;        
              }
	| case constant_expression colon statement 
              {/* printf(" |"); */
                  LabeledStatement *temp = new LabeledStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->value = 265;
                    $$ = temp;        
              }
	| default colon statement 
              {/* printf(" |"); */
                  LabeledStatement *temp = new LabeledStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 266;
                    $$ = temp;        
              }
	;

compound_statement
	: lkey rkey 
              {
                  CompoundStatement *temp = new CompoundStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 267;
                    $$ = temp;        
              }
	| lkey statement_list rkey 
              {
                  CompoundStatement *temp = new CompoundStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 268;
                    $$ = temp;        
              }
	| lkey declaration_list rkey
              {
                  CompoundStatement *temp = new CompoundStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 269;
                    $$ = temp;        
              }
	| lkey declaration_list statement_list rkey 
              {
                  CompoundStatement *temp = new CompoundStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4; 
                  temp->value = 270;
                    $$ = temp;        
              }
	;

declaration_list
	: declaration 
              {/* printf("declaration |"); */
                  DeclarationList *temp = new DeclarationList();
                  temp->a = $1;
                  temp->value = 271;
                    $$ = temp;      
              }
	| declaration_list declaration  
              {/* printf("declaration_list declaration |"); */
                  DeclarationList *temp = new DeclarationList();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 272;
                    $$ = temp;      
              }
	;

statement_list
	: statement 
              {/* printf("statement  |"); */
                  StatementList *temp = new StatementList();
                  temp->a = $1;
                  temp->value = 273;
                    $$ = temp;      
              }
	| statement_list statement 
              {/* printf("statement_list statement |"); */
                  StatementList *temp = new StatementList();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 274;
                    $$ = temp;      
              }
	;

expression_statement 
	: semicolon 
              {
                  ExpressionStatement *temp = new ExpressionStatement();
                  temp->a = $1;
                  temp->value = 275;
                    $$ = temp;      
              }
	| expression semicolon 
              {
                  ExpressionStatement *temp = new ExpressionStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 276;
                    $$ = temp;      
              }
	;

selection_statement
	: if lparen expression rparen statement 
              {/* printf("IF '(' expression ')' statement |"); */
                  SelectionStatement *temp = new SelectionStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->e = $5;
                  temp->value = 277;
                    $$ = temp;      
              }
	| if lparen expression rparen statement else statement 
              {/* printf("IF '(' expression ')' statement ELSE statement |"); */
                  SelectionStatement *temp = new SelectionStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->e = $5;
                  temp->f = $6;
                  temp->g = $7;
                  temp->value = 278;
                    $$ = temp;      
              }
	| switch lparen expression rparen statement 
              {/* printf("SWITCH '(' expression ')' statement |"); */
                  SelectionStatement *temp = new SelectionStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->e = $5;
                  temp->value = 279;
                    $$ = temp;      
              }
	;

iteration_statement
	: while lparen expression rparen statement 
              {/* printf("WHILE '(' expression ')' statement |"); */
                  IterationStatement *temp = new IterationStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->e = $5;
                  temp->value = 280;
                    $$ = temp;      
              }
	| do statement while lparen expression rparen semicolon 
              {
                  IterationStatement *temp = new IterationStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->e = $5;
                  temp->f = $6;
                  temp->g = $7;
                  temp->value = 281;
                    $$ = temp;      
              }
	| for lparen expression_statement expression_statement rparen statement 
              {/* printf("FOR '(' expression_statement expression_statement ')' statement |"); */
                  IterationStatement *temp = new IterationStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->e = $5;
                  temp->f = $6;
                  temp->value = 282;
                    $$ = temp;      
              }
	| for lparen expression_statement expression_statement expression rparen statement  
              {/* printf("FOR '(' expression_statement expression_statement expression ')' statement |"); */
                  IterationStatement *temp = new IterationStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->e = $5;
                  temp->f = $6;
                  temp->g = $7;
                  temp->value = 283;
                    $$ = temp;      
              }
	;

jump_statement
	: goto identifier semicolon 
              {
                  JumpStatement *temp = new JumpStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 284;
                    $$ = temp;        
              }
	| continue semicolon 
              {
                  JumpStatement *temp = new JumpStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 285;
                    $$ = temp;     
              }
	| break semicolon 
              {
                  JumpStatement *temp = new JumpStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 286;
                    $$ = temp;     
              }
	| return semicolon 
              {
                  JumpStatement *temp = new JumpStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 287;
                    $$ = temp;     
              }
	| return expression semicolon 
              {
                  JumpStatement *temp = new JumpStatement();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 288;
                    $$ = temp;     
              }
	;



external_declaration
 	: function_definition 
              {/* printf("function_definition | "); */
                  ExternalDeclaration *temp = new ExternalDeclaration();
                  temp->a = $1;
                  temp->value = 289;
                    $$ = temp;     
              } 
	| declaration         
              {/* printf("declaration | "); */
                  ExternalDeclaration *temp = new ExternalDeclaration();
                  temp->a = $1;
                  temp->value = 290;
                //  printf("ExternalDeclartion: declaration %d \n",temp->value);
                  $$ = temp;     
              }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement 
              {/* printf("declaration_specifiers declarator declaration_list compound_statement |"); */
                  FunctionDefinition *temp = new FunctionDefinition();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->d = $4;
                  temp->value = 291;
                    $$ = temp;     
              }
	| declaration_specifiers declarator compound_statement 
              {/* printf("declaration_specifiers declarator compound_statement |"); */
                  FunctionDefinition *temp = new FunctionDefinition();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 292;
                    $$ = temp;     
              }
	| declarator declaration_list compound_statement 
              {/* printf("declarator declaration_list compound_statement |"); */
                  FunctionDefinition *temp = new FunctionDefinition();
                  temp->a = $1;
                  temp->b = $2;
                  temp->c = $3;
                  temp->value = 293;
                    $$ = temp;     
              }
	| declarator compound_statement 
              {/* printf("declarator compound_statement |"); */
                  FunctionDefinition *temp = new FunctionDefinition();
                  temp->a = $1;
                  temp->b = $2;
                  temp->value = 294;
                    $$ = temp;     
              }
	;

%%
extern char yytext[];

int yyerror(char *s)
{
	fflush(stdout);
	printf("\n%s\n", s);
}

main(int argc,char **argv)
{
extern FILE* yyin;
ast = new Ast();
raizVariaveis = 0;
raizFuncoes = 0;
escopo = 0;
ordem = 0;
	      if ( argc > 1 )
	      {
		       printf("%s",argv[1]);
		       yyin = fopen( argv[1], "r" );
		    
	      }
	       yyparse();
                   treewalk(ast);
                   mainAst(ast,0);
//excluir
                   imprimirTabelaVariaveis(raizVariaveis);
}