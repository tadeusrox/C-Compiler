%option noyywrap yylineno
%{ 
extern "C" 
    { 
        int yylex(void); 
    }

#include "fila.h"
#include "ast.h"
#include "gramC.tab.h"

int oldstate;





int typedefidentifier = 0;
int structcont = 0;
int structidentifier();
int keycont = 0;
int typecont = 0;
struct no* raiz;
%}



%x COMMENT

LU ([l|u|L|U|lu|LU|ul|UL])
LF ([l|f|L|F|lf|LF|fl|FL])
D  [0-9]
L  [a-zA-Z_]

NOMEARC [0-9a-zA-Z_/ ]



%%

^"#"(.)*                                       {/*printf(" GCC-PREPROCESSOR");*/}


"auto"			{/*printf(" AUTO");*/ return AUTO;} 
"break"			{/*printf(" BREAK");*/ return BREAK;}
"case"			{/*printf(" CASE");*/ return CASE;}
"char"			{/*printf(" CHAR");*/  if(keycont >= 0) typecont = 1; return CHAR;}
"const"			{/*printf(" CONST");*/ return CONST;}
"continue"			{/*printf(" CONTINUE");*/ return CONTINUE;}
"default"			{/*printf(" DEFAULT");*/ return DEFAULT;}
"do"			{/*printf(" DO");*/ return DO;}
"double"			{/*printf(" DOUBLE");*/ return DOUBLE;}
"else"			{/*printf(" ELSE");*/ return ELSE;}
"enum"			{/*printf(" ENUM");*/ return ENUM;}
"extern"			{/*printf(" EXTERN");*/ return EXTERN;}
"float"			{/*printf(" FLOAT");*/ if(keycont == 0) typecont = 1;  return FLOAT;}
"for"			{/*printf(" FOR");*/ return FOR;}
"goto"			{/*printf(" GOTO");*/ return GOTO;}
"if"			{/*printf(" IF");*/ return IF;}
"int"			{/*printf(" INT");*/if(keycont >= 0) typecont = 1; return INT;}
"long"			{/*printf(" LONG");*/ if(keycont == 0) typecont = 1; return LONG;}
"register"			{/*printf(" REGISTER");*/ return REGISTER;}
"return"			{/*printf(" RETURN");*/ return RETURN;}
"short"			{/*printf(" SHORT");*/ if(keycont >= 0) typecont = 1; return SHORT;}
"signed"			{/*printf(" SIGNED");*/if(keycont == 0) typecont = 1; return SIGNED;}
"sizeof"			{/*printf(" SIZEOF");*/ return SIZEOF;}
"static"			{/*printf(" STATIC");*/ return STATIC;}
"struct"			{/*printf(" STRUCT");*/ if(keycont == 0) structcont = 1; return STRUCT;}
"switch"			{/*printf(" SWITCH");*/ return SWITCH;}
"typedef"			{/*printf(" TYPEDEF");*/ typedefidentifier = 1; return TYPEDEF;}
"union"			{/*printf(" UNION");*/ if(keycont == 0) structcont = 1; return UNION;}
"unsigned"			{/*printf(" UNSIGNED");*/ if(keycont == 0) typecont = 1; return UNSIGNED;}
"void"			{/*printf(" VOID");*/ return VOID;}
"volatile"			{/*printf(" VOLATILE");*/ return VOLATILE;}
"while"			{/*printf(" WHILE");*/ return WHILE;} 

"..."			{/*printf(" ELLIPSIS");*/ return(ELLIPSIS); }

">>="			{/*printf(" RIGHT_ASSIGN");*/ return(RIGHT_ASSIGN); }
"<<="			{/*printf(" LEFT_ASSIGN");*/ return(LEFT_ASSIGN); }
"+="			{/*printf(" ADD_ASSIGN");*/ return(ADD_ASSIGN); }
"-="			{/*printf(" SUB_ASSIGN");*/ return(SUB_ASSIGN); }
"*="			{/*printf(" MUL_ASSIGN");*/ return(MUL_ASSIGN); }
"/="			{/*printf(" DIV_ASSIGN");*/ return(DIV_ASSIGN); }
"%="			{/*printf(" MOD_ASSIGN");*/ return(MOD_ASSIGN); }
"&="			{/*printf(" AND_ASSIGN");*/ return(AND_ASSIGN); }
"^="			{/*printf(" XOR_ASSIGN");*/ return(XOR_ASSIGN); }
"|="			{/*printf(" OR_ASSIGN");*/ return(OR_ASSIGN); }

">>"			{ /*printf(" RIGHT_OP");*/ return(RIGHT_OP); }
"<<"			{ /*printf(" LEFT_OP");*/ return(LEFT_OP); }
"++"			{ /*printf(" INC_OP");*/ return(INC_OP); }
"--"			{ /*printf(" DEC_OP");*/ return(DEC_OP); }
"->"			{ /*printf(" PTR_OP");*/ return(PTR_OP); }
"&&"			{ /*printf(" AND_OP");*/ return(AND_OP); }
"||"			{ /*printf(" OR_OP");*/ return(OR_OP); }
"<="			{ /*printf(" LE_OP");*/ return(LE_OP); }
">="			{ /*printf(" GE_OP");*/ return(GE_OP); }
"=="			{ /*printf(" EQ_OP");*/ return(EQ_OP); }
"!="			{ /*printf(" NE_OP");*/ return(NE_OP); }

";"			{/* printf(" ;");*/ return(';'); }
("{"|"<%")			{/* printf(" {");*/ keycont++;return('{'); }
("}"|"%>")			{/* printf(" }");*/ keycont--; return('}'); }
","			{/* printf(" ,");*/ return(','); }
":"			{/* printf(" :");*/ return(':'); }
"="			{ /*printf(" =");*/ return('='); }
"("			{ /*printf(" (");*/ return('('); }
")"			{ /*printf(" )");*/ return(')'); }
("["|"<:")			{ /*printf(" [");*/ return('['); }
("]"|":>")			{ /*printf(" ]");*/ return(']'); }
"."			{ /*printf(" .");*/ return('.'); }
"&"			{ /*printf(" &");*/ return('&'); }
"!"			{ /*printf(" !");*/ return('!'); }
"~"			{ /*printf(" ~");*/ return('~'); }
"-"			{ /*printf(" -");*/ return('-'); }
"+"			{ /*printf(" +");*/ return('+'); }
"*"			{ /*printf(" *");*/ return('*'); }
"/"			{ /*printf(" /");*/ return('/'); }
"%"			{ /*printf(" %");*/ return('%'); }
"<"			{ /*printf(" <");*/ return('<'); }
">"			{ /*printf(" >");*/ return('>'); }
"^"			{ /*printf(" ^");*/ return('^'); }
"|"			{ /*printf(" |");*/ return('|'); }
"?"			{ /*printf(" ?");*/ return('?'); }

"0"{LU}{0,2}			{/*printf(" CONSTANT");*/ yylval.type = 0;  return CONSTANT;}
-?[1-9][0-9]*{LU}{0,2}		{/*printf(" CONSTANT");*/ yylval.type = 1;  return CONSTANT;}

-?[0-9]+"."[0-9]*{LF}?	     	|	
-?"."[0-9]+{LF}?	 	|
-?[0-9]+E[-+]?[0-9]+{LF}?	|
-?[0-9]+"."[0-9]+[E|e][-+]?[0-9]+{LF}?  |
-?"."[0-9]+E[-+]?[0-9]+{LF}?	{/*printf(" CONSTANT");*/ yylval.type = 1;  return CONSTANT;}

-?[0][x|X][0-9|A-F|a-f]*{LU}?	{/*printf(" CONSTANT HEX");*/ yylval.type = 1;  return CONSTANT;}

-?[0][0-7]*{LU}? 	            {/*printf(" CONSTANT OCT");*/ yylval.type = 1;   return CONSTANT;}

"true" | "false"		{/*printf(" CONSTANT");*/  yylval.type = 2;  return CONSTANT;}

[L]?\"(\\.|[^\\"])*\"		{/*printf(" STRING");*/ yylval.type = 3;   return STRING_LITERAL;}

  

[\'][A-Z|a-z|0-9][\'] |
[\']["\n"|"\t"|"\v"|"\b"|"\r"|"\f"|"\a"|"\\"|"\?"|"\'"|"\""|"\0"][\'] yylval.type = 1; {return CONSTANT;}

{L}({L}|{D})* {yylval.idname = yytext;  return(structidentifier());}



"/*" {oldstate = YY_START; BEGIN COMMENT;} 
<COMMENT>"*/" {BEGIN oldstate;printf(" COMMENT");}
<COMMENT>.|\n
<COMMENT><<EOF>> {BEGIN oldstate; /*printf(" UNTERMINED COMMENT");*/}

"//"(.)*                            {/*printf("comment");*/}
"\n"                                {printf("\n");}
.			{  }

%% 

int structidentifier()
{
     //printf("\n\n%s\n\n%d\n\n\n",param,buscar(&raiz,param));
//printf("\nfun |%s|\n",param);
//printf("\nfun2 |%s|\n",yytext);
//printf("\n type =  %d cont = %d\n",typedefidentifier,typecont);
     if(buscar(&raiz,yytext) == 1)
     {
        // printf(" 2 STRUCT_TYPE");
         //strcpy(yylval.idname,yytext); //yytext
         return STRUCT_TYPE;
     }
     if(typedefidentifier == 1 && structcont == 1)
     {  
          typedefidentifier=-1;
          structcont=-1;
         // printf(" 1 IDENTIFIER");
          //strcpy(yylval.idname,yytext); //yytext
          return IDENTIFIER;
     }
     else if(typedefidentifier == -1 && structcont == -1 && keycont == 0)
     {
         // printf("\nmandou pra inserir |%s|\n",yytext);
          inserir(&raiz,yytext);
         // printf(" 3 IDENTIFIER");
          typedefidentifier = 0;
          structcont = 0;
          //strcpy(yylval.idname,yytext); //yytext
          return IDENTIFIER;
     } 
     else if(typedefidentifier == 1 && typecont == 1 && keycont == 0)
     {
          // printf("\nmandou pra inserir |%s|\n",yytext);
          inserir(&raiz,yytext);
        //  printf(" 4 IDENTIFIER");
          typedefidentifier = 0;
          structcont = 0;
         // strcpy(yylval.idname,yytext); //yytext
          return IDENTIFIER;
     }
     else if(typedefidentifier == 1 && typecont == 1)
     {
         //  printf("\nmandou pra inserir |%s|\n",yytext);
          inserir(&raiz,yytext);
         // printf(" 6 IDENTIFIER");
          typedefidentifier = 0;
          structcont = 0;
         // strcpy(yylval.idname,yytext); //yytext 
          return IDENTIFIER;
     }
     else 
     {
         // printf(" 5 IDENTIFIER");
         // strcpy(yylval.idname,yytext); //yytext
          return IDENTIFIER;
     }
}