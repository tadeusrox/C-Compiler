bison -d gramC.y -v
flex flexC.l
g++ -o out gramC.tab.c lex.yy.c -lfl