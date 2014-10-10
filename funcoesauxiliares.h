// 82 = ';' 300 = id 67 = ',' 83 = '='
/*106 107 108 109 110 111 operadores*/
//typedefs 172 173 174 175 176
//tipos vod

//#define DEBUG
int typeSpecifier(Ast* node, int escopo);
int statement(Ast *node,int escopo);
char* initDeclaratorList(Ast *node,int escopo, int type);
int initializer(Ast* node, int escopo);
char* initDeclarator(Ast *node,int escopo);
char* initDeclarator(Ast *node,int escopo,int type);
int initializerList(Ast *node, int escopo);
int declarationSpecifiers(Ast *node,int escopo);
int functionDefinition(Ast *node,int escopo);
int initializer(Ast* node, int escopo);
int expression(Ast *node,int escopo);
int typeQualifierList(Ast *node, int escopo);
int assignmentExpression(Ast *node,int escopo);
int parameterTypeList(Ast *node, int escopo);
int castExpression(Ast *node, int escopo);
int pointer(Ast *node, int escopo);
int conditionalExpression(Ast *node,int escopo);
int constantExpression(Ast *node,int escopo);
int abstractDeclarator(Ast* node, int escopo);
char* declarator(Ast *node,int escopo);
int compoundStatement(Ast *node,int escopo);
//////////////////////////////////////////////////////////////////////////////////////////


int typeQualifier(Ast *node, int escopo)
{
  switch(node->value)
  {
    // 213 const 214 volatile
    default: break;
  }
  return 0;
}

int enumerator(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 211: /* identifier */; break;
    case 212: /* identifier */; constantExpression(node->c,escopo); break;
    default: break;
  }
  return 0;
}
int enumeratorList(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 209: enumerator(node->a,escopo); break;
    case 210: enumeratorList(node->a,escopo); enumerator(node->c,escopo); break;
    default: break;
  }
  return 0;
}
int enumSpecifier(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 206: enumeratorList(node->c,escopo); break;
    case 207: enumeratorList(node->d,escopo); break;
    case 208: /*dafuk*/
    default: break;
  }
  return 0;
}
int structDeclarator(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 203: declarator(node->a,escopo); break;
    case 204: constantExpression(node->b,escopo); break;
    case 205: declarator(node->a,escopo); constantExpression(node->c,escopo); break;
    default: break;
  }
  return 0;
}

int structDeclaratorList(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 201: structDeclarator(node->a,escopo); break;
    case 202: structDeclaratorList(node->a,escopo); structDeclarator(node->c,escopo); break;
    default: break;
  }
  return 0;
}
int specifierQualifierList(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 197: typeSpecifier(node->a,escopo); specifierQualifierList(node->b,escopo); break;
    case 198: return typeSpecifier(node->a,escopo); break;
    case 199: typeQualifier(node->a,escopo); specifierQualifierList(node->b,escopo); break;
    case 200: typeQualifier(node->a,escopo); break;
    default: break;
  }
  return 0;
}

int structDeclaration(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 196: specifierQualifierList(node->a,escopo); structDeclaratorList(node->b,escopo); break;
    default: break;
  }
  return 0;
}

int structDeclarationList(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 194: structDeclaration(node->a,escopo); break;
    case 195: structDeclarationList(node->a,escopo); structDeclaration(node->b,escopo); break;
    default: break;
  }
}

int structOrUnionSpecifier(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 189: structDeclarationList(node->d,escopo); break;
    case 190: structDeclarationList(node->c,escopo); break;
    case 191: break;
    default: break;
  }
}

int typeSpecifier(Ast* node, int escopo)
{
    switch(node->value)
    {
      case 177: 
        printf("Variavel declarada como void"); 
        return -1;
      case 178: return 1; break; //return char 
      case 179: return 1; break; //return int
      case 180: return 1; break; //return int
      case 181: return 1; break; //return int
      case 182: return 1; break; //return int
      case 183: return 1; break; //return int
      case 184: return 1; break; //return int
      case 185: return 1; break; //return int
      case 186: structOrUnionSpecifier(node->a,escopo); break;
      case 187: enumSpecifier(node->a,escopo); break;
      case 188: /* structType */ break;
    default: break;
    }
}

char* initDeclaratorList(Ast *node,int escopo, int type)
{
  char *name;
  int resultado;
  switch(node->value)
  {
    case 168:  name = initDeclarator(node->a,escopo,type); 
	      //um inserir aqui talves
	      #ifdef DEBUG
	      printf("\n name 168 = %s type = %d\n",name,type);
	      #endif
	    if(procurarVariavel(raizVariaveis,name) == 0)
	    {
	      #ifdef DEBUG
	      printf("\n6\n");
	      #endif
	   // insereVariavel(&raizVariaveis,escopo,name,type,0);
	    }
	    else
	    {
	         //  printf("\n2\n");
	          printf("Variavel já declarada");
	    }
	      return name;
	    break;
    case 169:   
                name =  initDeclaratorList(node->a,escopo,type); 
	     if(procurarVariavel(raizVariaveis,name) == 0)
	    {
	    //  printf("\n1\n");
	    //inserirDeclaracaoVariaveis(&raizVariaveis,escopo,name,type,0);  
	    }
	    else
	    {
	          printf("Variavel já declarada");
	    }
	    name = initDeclarator(node->c,escopo,type); 
	    if(procurarVariavel(raizVariaveis,name) == 0)
	    {
	      #ifdef DEBUG
	      printf("\n5\n");
	      #endif
	    insereVariavel(&raizVariaveis,escopo,name,type,0);
	    }
	    else
	    {
	         //  printf("\n2\n");
	          printf("Variavel já declarada");
	    }
	    return 0;
	    break;
    default: break;
  }
}



int storageClassSpecifier(Ast *node, int escopo)
{
  switch(node->value)
  {
    /* typedefs etc.. */
    default: break;
  }
}

int declarationSpecifiers(Ast *node,int escopo)
{
  switch(node->value)
  {
    case 162: storageClassSpecifier(node->a,escopo); break;
    case 163: storageClassSpecifier(node->a,escopo); declarationSpecifiers(node->b,escopo); break;
    case 164: return typeSpecifier(node->a,escopo); break;
    case 165: typeSpecifier(node->a,escopo); declarationSpecifiers(node->b,escopo); break;
    case 166: typeQualifier(node->a,escopo); break;
    case 167: typeQualifier(node->a,escopo); declarationSpecifiers(node->b,escopo); break;
    default: break;
  }
}

char* identifierList(Ast *node, int escopo)
{ //vinicius
  char *name;
  

	    
  switch(node->value)
  {
    case 237:   name = node->a->text; 	    
                if(procurarVariavel(raizVariaveis,name) == 0)
	    {
	      #ifdef DEBUG
	      printf("\n6\n");
	      #endif
	    insereVariavel(&raizVariaveis,escopo,name,0,0);
// 	    if(nomefuncao != 0)
// 	    {
// 	       novoParametro(&raizParametros,nomefuncao,ordem,name,0,0);
// 	    }
	    }
	    else
	    {
	         //  printf("\n2\n");
	          printf("\n\n\nparametro %s já declarado\n\n\n ",name);
	    }
              
	  break;
    case 238: 
              identifierList(node->a,escopo);
	  name = node->c->text;
	  if(procurarVariavel(raizVariaveis,name) == 0)
	    {
	      #ifdef DEBUG
	      printf("\n4 oi\n");
	      #endif
	    insereVariavel(&raizVariaveis,escopo,name,0,0);
// /*	         	    if(nomefuncao != 0)
// 	                {
// 	                    novoParametro(&raizParametros,nomefuncao,ordem,name,0,0);
// 	                 }*/
	    }
	    else
	    {
	         //  printf("\n2\n");
	          printf("\n\n\nparametro %s já declarado\n\n\n ",name);
	    }
	  break;
    default: break;
  }
}


int directAbstractDeclarator(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 244: abstractDeclarator(node->a,escopo); break;
    case 245: break;
    case 246: constantExpression(node->b,escopo); break;
    case 247: directAbstractDeclarator(node->a,escopo); break;
    case 248: directAbstractDeclarator(node->a,escopo);
              constantExpression(node->c,escopo);
	  break;
    case 249: break;
    case 250: parameterTypeList(node->b,escopo); break;
    case 251: directAbstractDeclarator(node->a,escopo); break;
    case 252: directAbstractDeclarator(node->a,escopo); parameterTypeList(node->c,escopo); break;
    default: break;
  }
  return 0;
}

int abstractDeclarator(Ast* node, int escopo)
{
  switch(node->value)
  {
    case 241: pointer(node->a,escopo); break;
    case 242: directAbstractDeclarator(node->a,escopo); break;
    case 243: pointer(node->a,escopo); directAbstractDeclarator(node->b,escopo); break;
    default: break;
  }
  return 0;
}
int parameterDeclaration(Ast* node, int escopo)
{
  char *name;
  int type;
  switch(node->value)
  {
    case 234: type = declarationSpecifiers(node->a,escopo); 
              name = declarator(node->b,escopo); 
	  #ifdef DEBUG
              printf("\n\n name 234 = %s type 234 = %d\n\n",name,type);
	  #endif
	  if(name != 0)
	  {
                 if(procurarVariavel(raizVariaveis,name) == 0)
	     {
	       #ifdef DEBUG
	       printf("\n234\n");
	       #endif
	       insereVariavel(&raizVariaveis,escopo,name,type,0);
	     }
	     else
	     {
	          printf("Variavel já declarada");
	     }
	  }
	  break;
    case 235: declarationSpecifiers(node->a,escopo); abstractDeclarator(node->b,escopo); break;
    case 236: declarationSpecifiers(node->a,escopo); break;
    default: break;
  }
  return 0;
}

int parameterList(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 232: parameterDeclaration(node->a,escopo); 
              #ifdef DEBUG
              printf("\n232\n");
	  #endif
              break;
    case 233: parameterList(node->a,escopo); parameterDeclaration(node->c,escopo); break;
    default: break;
  }
  return 0;
}

int parameterTypeList(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 230: 
              #ifdef DEBUG
              printf("\n\n\n 230 \n\n\n");
	  #endif
              parameterList(node->a,escopo); 
	  break;
    case 231: 
              #ifdef DEBUG
              printf("\n\n\n 231 \n\n\n");
	  #endif
              parameterList(node->a,escopo); break;
    default: break;
  }
  return 0;
}

char* directDeclarator(Ast *node,int escopo)
{
  char *name = 0;
  char **param = 0;
  switch(node->value)
  {
    case 217:  name = node->a->text;
               #ifdef DEBUG
               printf("\n\n name 217 = %s\n\n",name);
	   #endif
               return node->a->text;
	   break; //return id
    case 218:
              name = declarator(node->b,escopo); 
	  #ifdef DEBUG
	  printf("\n\n name 218 = %s\n\n",name);
	  #endif
	  return name;
	  break;
    case 219: name = directDeclarator(node->a,escopo); constantExpression(node->c,escopo); 
           //   return "2";
                #ifdef DEBUG
               printf("\n\n name 219 = %s\n\n",name);
	   #endif
               return name;
	  break;
    case 220: name = directDeclarator(node->a,escopo); 
    #ifdef DEBUG
               printf("\n\n name 220 = %s\n\n",name);
	   #endif
              return name;
	  break;
    case 221: 
                name = directDeclarator(node->a,escopo); 
	        #ifdef DEBUG
               printf("\n\n name 221 = %s\n\n",name);
	   #endif
	    parameterTypeList(node->c,escopo);
           //   return "4";
           return name;
	  break;
    case 222: 
               ordem = 0;
//	   printf("\n\n\n\n222 %s \n\n\n\n",nomefuncao);
               identifierList(node->c,escopo+1); //para quando funcao e declarada do 
	                                     //tipo a(b,c,d)int a,int b,int c{blabla}
	   ordem = 0;
               return directDeclarator(node->a,escopo);
	   
	//   return "5";
	   break;
    case 223: directDeclarator(node->a,escopo);
            //  return "6";
              break;
    default: break;
  }
}

int pointer(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 224: return 1; break;
    case 225: typeQualifierList(node->b,escopo); return 1; break;
    case 226: return 1+pointer(node->b,escopo); break;
    case 227: typeQualifierList(node->b,escopo); pointer(node->c,escopo); break;
    default: break;
  }
}

int typeQualifierList(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 228: typeQualifier(node->a,escopo); break;
    case 229: typeQualifierList(node->a,escopo); typeQualifier(node->b,escopo); break;
    default: break;
  }
  return 0;
}

char* declarator(Ast *node,int escopo)
{
  char *name = 0;
  switch(node->value)
  {
    case 215: 
             #ifdef DEBUG
               printf("\n215\n");
	   #endif
              pointer(node->a,escopo); 
	  return directDeclarator(node->b,escopo); 
	  break;
    case 216: //printf("\naqui2\n");
              name = directDeclarator(node->a,escopo);
	  //printf("\naqui3\n");
	 
	  #ifdef DEBUG
	  printf("\n\n\n Name 216 = %s\n\n\n",name);
	  #endif
	  return name;
	  break;
    default: break;
  }
}

char* declarator(Ast *node,int escopo, int type)
{
  int pointerCount;
  char *name;
  switch(node->value)
  {
    case 215: 
              pointerCount = pointer(node->a,escopo); 
	  name = directDeclarator(node->b,escopo);
	  if(procurarVariavel(raizVariaveis,name) == 0)
	  {
	    #ifdef DEBUG
	    printf("\n3\n");
	    #endif
	    insereVariavel(&raizVariaveis,escopo,name,type,pointerCount);
	  }
	  else if(procurarVariavel(raizVariaveis,name) == 2)
	  {
	      alteraTipo(&raizVariaveis,name,type,pointerCount);
	  }
	  else
	  {
	          printf("Variavel já declarada");
	  }
	  return 0;
	  break;
	  
        case 216: 
              name = directDeclarator(node->a,escopo);
	  //printf("\naqui3\n");
	  #ifdef DEBUG
	  printf("\n\n\n name 216 = %s type = %d\n\n\n",name,type);
	  #endif
	    if(name != 0)
	    {
                 if(procurarVariavel(raizVariaveis,name) == 0)
	     {
	       printf("\n4\n");
	       insereVariavel(&raizVariaveis,escopo,name,type,0);
	     }
	     else
	     {
	          printf("Variavel já declarada");
	     }
	    }
	    
	    
	  return name;
	  break;
    default: break;
  }
}

int initializerList(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 256: initializer(node->a,escopo); break;
    case 257: initializerList(node->a,escopo); initializer(node->c,escopo); break;
    default: break;
  }
  return 0;
}

int initializer(Ast* node, int escopo)
{
  switch(node->value)
  {
    case 253: assignmentExpression(node->a,escopo); break;
    case 254: initializerList(node->b,escopo); break;
    case 255: initializerList(node->b,escopo); break;
    default: break;
  }
  return 0;
}

char* initDeclarator(Ast *node,int escopo) //////////duplicada
{
  char *name;
   switch(node->value)
   {
     case 170:  name = declarator(node->a,escopo); 
     #ifdef DEBUG
                printf("\n name 170 = %s",name);
	    #endif
                return name;
	    break;
     case 171: declarator(node->a,escopo); initializer(node->c,escopo); break;
     default: break;
   }
}

char* initDeclarator(Ast *node,int escopo,int type) ///////duplicada
{
  char *name;
   switch(node->value)
   {
     case 170:  name = declarator(node->a,escopo,type); 
     #ifdef DEBUG
                printf("\n name 170 = %s type = %d",name,type);
	    #endif
                return name;
	    break;
     case 171: declarator(node->a,escopo,type); initializer(node->c,escopo); break;
     default: break;
   }
}

int declaration(Ast *node,int escopo)
{
  char *name = 0;
  int type;
   switch(node->value)
   {
     case 160: declarationSpecifiers(node->a,escopo); break;
     case 161: 
                type = declarationSpecifiers(node->a,escopo);
	    name = initDeclaratorList(node->b,escopo,type); 
	    if(name != 0)
	    {
                 if(procurarVariavel(raizVariaveis,name) == 0)
	     {
	       #ifdef DEBUG
	       printf("\n161\n");
	       #endif
	       insereVariavel(&raizVariaveis,escopo,name,type,0);
	     }
	     else if(procurarVariavel(raizVariaveis,name) == 2)
	    {
	      alteraTipo(&raizVariaveis,name,type,0);
	    }
	     else
	     {
	          printf("Variavel já declarada");
	     }
	    }
	    /*semicolon*/ break;
     default: break;
   }
   
   return 0;
}

int declarationList(Ast* node,int escopo)
{
 
     switch(node->value)
     {
          case 271: declaration(node->a,escopo); break;
          case 272: declarationList(node->a,escopo); declaration(node->b,escopo); break;
          default: break;
     }
     
       return 0;
}

int assignmentOperator(Ast *node, int escopo)
{
   switch(node->value)
   {
     case 146: /* equal */ break;
     default: break;
   }
   return 0;   
}

int primaryExpression(Ast *node,int escopo)
{
  int temp;
   switch(node->value)
   {
     case 86:// printf("\n\n\n %d \n\n\n",retornarTipoVariavel(raizVariaveis, node->a->text));
              temp = retornarTipoVariavel(raizVariaveis, node->a->text);
	  if(temp == -12)
	  {
	    temp = retornarTipoFuncao(raizFuncoes,node->a->text);
	  }
              if(temp == -12)
	  {
	    printf("\n86\n");
	    printf("\n variavel '%s' não encontrada (uso de variavel nao declarada) \n",node->a->text);
	  //procurar funcao
	  }
              return temp; 
	  break;
     case 87: return node->a->value; break; //constant
     case 88: return 4; break;
     case 89: return expression(node->b,escopo); break;
     default: break;
   }
   return 0;   
}

int argumentExpressionList(Ast *node, int escopo) //full
{
  switch(node->value)
  {
    case 98: assignmentExpression(node->a,escopo); break;
    case 99: argumentExpressionList(node->a,escopo); assignmentExpression(node->c,escopo); break;
    default: break;
  }
  return 0;
}

int postfixExpression(Ast *node, int escopo)
{
    int type1,type2,type3;
   switch(node->value)
   {
     case 90: type1 = primaryExpression(node->a,escopo); //primary_expression 
            //  printf("\n\n\n type3 %d \n\n\n",type1);
	  return type1;
              break;
     case 91:  //postfix_expression lbracket expression rbracket 
       	  type3 = expression(node->c,escopo); 
              type2 = postfixExpression(node->a,escopo); 
	  //printf("\n\n\n type2 %d \n\n\n",type2);
	  if(type2 < 99 || type2 == 0)
	  {
	    //printf("\ntype2 %d \n",type2);
	    printf("\n\n\n requer ponteiro para fazer essa operacao \n\n\n");
	  }
	  //printf("\n\n\n type 3 %d \n\n\n",type3);
	  if(type3 != 1 && type3 != 0)
	  {
	      printf("\n\n\n type 3 %d \n\n\n",type3);
	    printf("\n\n\n requer inteiro [ aqui ]\n\n\n");
	  }
              return type2 - 100; //tipo + caso 91;
	  break;
     case 92:
              postfixExpression(node->a,escopo);
	  break;
	//  return 0;
     case 93:
              postfixExpression(node->a,escopo); 
	  argumentExpressionList(node->c,escopo); 
	  break;
     case 94: 
              postfixExpression(node->a,escopo);
	  //identfier
              break;
     case 95: 
              postfixExpression(node->a,escopo);
	  //identifier
	  break;
     case 96:
              postfixExpression(node->a,escopo);
	  break;
     case 97: postfixExpression(node->a,escopo);
              break;
     default: break;
   }
   

   return 0;
}

int unaryExpression(Ast *node,int escopo)
{
  int type1;
   switch(node->value)
   {
     case 100: 
               
               type1 = postfixExpression(node->a,escopo); //postfix_expression 
	  // printf("\n\n\n type4 %d \n\n\n",type1);
	   return type1;
	   break;
     case 101: unaryExpression(node->b,escopo);
               break;
     case 102: unaryExpression(node->b,escopo);
               break;
     case 103: unaryExpression(node->a,escopo);
               castExpression(node->b,escopo);
               break;
     case 104: unaryExpression(node->b,escopo);
               break;
     case 105: unaryExpression(node->c,escopo);
               break;
     default: break;
   }
   return 0;
}

int typeName(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 239: return specifierQualifierList(node->a,escopo); break;
    case 240: specifierQualifierList(node->a,escopo); abstractDeclarator(node->b,escopo); break;
    default: break;
  }
  return 0;
}

int castExpression(Ast *node, int escopo)
{
  int type1;
  int type2;
   switch(node->value)
   {
     case 112: return unaryExpression(node->a,escopo); break; //unary_expression 
     case 113: //lparen type_name rparen cast_expression 
               type2 = typeName(node->b,escopo); 
               type1 = castExpression(node->d,escopo);   
	   return type2;
	   break; 
     default: break;
   }
   return 0;
}

int multiplicativeExpression(Ast *node, int escopo)
{
  int type1, type2;
  
   switch(node->value)
   {
     case 114: return castExpression(node->a,escopo); break; //cast_expression 
     case 115: //multiplicative_expression mul_sign cast_expression 
               type1 = multiplicativeExpression(node->a,escopo); 
	   type2 = castExpression(node->c,escopo);
	   if(type1 != type2)
	   {
	     printf("\nusando o operador * entre variaveis incompativeis\n");
	   }
	   return type1;
               break;
     case 116: //multiplicative_expression div_sign cast_expression
               type1 = multiplicativeExpression(node->a,escopo); 
	   type2 = castExpression(node->c,escopo);
	   if(type1 != type2)
	   {
	     printf("\nusando o operador / entre variaveis incompativeis\n");
	   }
	   return type1;
	   break;
     case 117://multiplicative_expression percent cast_expression 
               type1 = multiplicativeExpression(node->a,escopo);
	   type2 = castExpression(node->c,escopo);
	   if(type1 != type2)
	   {
	     printf("\nusando o operador mod entre variaveis incompativeis\n");
	   }
	   return type2;
	   break;
     default: break;
   }
   return 0;
}

int additiveExpression(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 118: return multiplicativeExpression(node->a,escopo); break; //multiplicative_expression 
    
    case 119: 
               additiveExpression(node->a,escopo); 
	   multiplicativeExpression(node->c,escopo); //checartipos
	   break;
    case 120: 
               additiveExpression(node->a,escopo); 
	   multiplicativeExpression(node->c,escopo); //checartipos
	   break;	   
    default: break;
  }
  return 0;
}

int shiftExpression(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 121: return additiveExpression(node->a,escopo); break; //additive_expression 
    case 122: 
               shiftExpression(node->a,escopo); 
	   additiveExpression(node->c,escopo); //checartipo
	   break;
    case 123: 
               shiftExpression(node->a,escopo); 
	   additiveExpression(node->c,escopo); //checartipos
    default: break;
  }
  return 0;
}
int relationalExpression(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 124: return shiftExpression(node->a,escopo); break; //shift_expression 
    case 125: 
               relationalExpression(node->a,escopo); 
	   shiftExpression(node->c,escopo); //checartipos
	   break;
    case 126: 
               relationalExpression(node->a,escopo); 
	   shiftExpression(node->c,escopo); //checartipos
	   break;
    case 127: 
               relationalExpression(node->a,escopo); 
	   shiftExpression(node->c,escopo); //checartipos
	   break;
    case 128: 
               relationalExpression(node->a,escopo); 
	   shiftExpression(node->c,escopo); //checartipos
	   break;
    default: break;
  }
  return 0;
}


int equalityExpression(Ast *node,int escopo)
{
  switch(node->value)
  {
    case 129: return relationalExpression(node->a,escopo); break; //relational_expression
    case 130: 
               equalityExpression(node->a,escopo); 
	   relationalExpression(node->c,escopo); //checartipos
	   break;
    case 131: 
               equalityExpression(node->a,escopo); 
	   relationalExpression(node->c,escopo); //checartipos
	   break;	   
    default: break;
  }
  return 0;
}

int andExpression(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 132: return equalityExpression(node->a,escopo); break; //equality_expression 
    case 133: 
               andExpression(node->a,escopo); 
	   equalityExpression(node->c,escopo); //checartipos
	   break;
    default: break;
  }
  return 0;
}


int exclusiveOrExpression(Ast* node, int escopo)
{
  switch(node->value)
  {
    case 134: return andExpression(node->a,escopo); break; //and_expression 
    case 135: 
               exclusiveOrExpression(node->a,escopo); 
	   andExpression(node->c,escopo); //checartipos
	   break;    
    default: break;
  }
  return 0;
}

int inclusiveOrExpression(Ast *node,int escopo)
{
  switch(node->value)
  {
    case 136: return exclusiveOrExpression(node->a,escopo); break; //exclusive_or_expression 
    case 137: 
               inclusiveOrExpression(node->a,escopo); 
	   exclusiveOrExpression(node->c,escopo); //checartipos
	   break;    
    default: break;
  }
  return 0;
}

int logicalAndExpression(Ast *node, int escopo)
{
     switch(node->value)
     {
       case 138: return inclusiveOrExpression(node->a,escopo); //inclusive_or_expression 
        break;
        case 139: 
               logicalAndExpression(node->a,escopo); 
	   inclusiveOrExpression(node->c,escopo); //checartipos
	   break; 
       default: break;
     }
     return 0;
}
int logicalOrExpression(Ast *node,int escopo)
{
     switch(node->value)
     {
       case 140: return logicalAndExpression(node->a,escopo); break; //logical_and_expression 
       case 141: 
               logicalOrExpression(node->a,escopo); 
               logicalAndExpression(node->c,escopo);
	   break; 
       default: break;
     }
     return 0;
}

int conditionalExpression(Ast *node,int escopo)
{
  switch(node->value)
  {
    case 142: return logicalOrExpression(node->a,escopo); break; //logical_or_expression 
           case 143: 
               logicalOrExpression(node->a,escopo); 
    	   expression(node->c,escopo); //checartipos
	   conditionalExpression(node->e,escopo);
	   break; 
    default: break;
  }
  return 0;
}

int assignmentExpression(Ast *node,int escopo)
{
   int tipo1;
   int tipo2;
   switch(node->value)
   {
     case 144: 
               return conditionalExpression(node->a,escopo); // conditional_expression 
	   break;
     case 145://unary_expression assignment_operator assignment_expression 
              tipo1 = unaryExpression(node->a,escopo);
	  assignmentOperator(node->b,escopo);
	  tipo2 = assignmentExpression(node->c,escopo); //
	  //printf("\n\n\n%d %d\n\n\n",tipo1,tipo2);

	  
	  if(tipo1 != tipo2)
	  {
	       printf("\n\n\n  atribuição de tipos diferentes %d %d \n",tipo1,tipo2);
	  }
	  break;
     default: break;
   }
   return 0;
}

int expression(Ast *node,int escopo)
{
    switch(node->value)
    {
      case 157: return assignmentExpression(node->a,escopo); break;
      case 158: expression(node->a,escopo); assignmentExpression(node->c,escopo); break;
      default: break;
    }
    return 0;
}

int constantExpression(Ast *node,int escopo)
{
   switch(node->value)
   {
     case 159:
                 conditionalExpression(node->a,escopo);
	     break;
     default: break;
   }
}

int expressionStatement(Ast *node,int escopo)
{
    switch(node->value)
    {
      case 275: break;
      case 276: return expression(node->a,escopo); break;
      default: break;
    }
    return 0;
}


int jumpStatement(Ast *node, int escopo)
{
    switch(node->value)
    {
      case 284: break;
      case 285: break;
      case 286: break;
      case 287: break;
      case 288: expression(node->b,escopo); /*tipo certo*/  break;
      default: break;
    }
}

int labeledStatement(Ast *node, int escopo)
{
   switch(node->value)
   {
     case 264: /* identifier */ statement(node->c,escopo); break;
     case 265: constantExpression(node->b,escopo); statement(node->c,escopo); break;
     case 266: statement(node->c,escopo); break;
     default: break;
   }
   return 0;
}

int selectionStatement(Ast *node,int escopo)
{
  switch(node->value)
  {
    case 277: expression(node->c,escopo); statement(node->d,escopo); break;
    case 278: expression(node->c,escopo); statement(node->e,escopo); statement(node->g,escopo); break;
    case 279: expression(node->c,escopo); statement(node->e,escopo); break;
    default: break;
  }
  return 0;
}

int iterationStatement(Ast *node, int escopo)
{
  switch(node->value)
  {
    case 280: expression(node->c,escopo); statement(node->e,escopo); break;
    case 281: statement(node->b,escopo); expression(node->e,escopo); break;
    case 282: expressionStatement(node->c,escopo); 
              expressionStatement(node->d,escopo); 
	  statement(node->f,escopo); 
	  break;
    case 283: expressionStatement(node->c,escopo); 
              expressionStatement(node->d,escopo); 
	  expression(node->e,escopo); 
	  statement(node->g,escopo); 
	  break;
    default: break;
  }
  return 0;
}

int statement(Ast *node,int escopo)
{
   switch(node->value)
   {
     case 258: labeledStatement(node->a,escopo); break;
     case 259: compoundStatement(node->a,escopo); break;
     case 260: return expressionStatement(node->a,escopo); break;
     case 261: selectionStatement(node->a,escopo); break;
     case 262: iterationStatement(node->a,escopo); break;
     case 263: return jumpStatement(node->a,escopo); break;
     default: break;
   }
   return 0;
}

int statementList(Ast* node,int escopo)
{
  switch(node->value)
  {
    case 273: return statement(node->a,escopo); break;
    case 274: statementList(node->a,escopo); statement(node->b,escopo); break;
    default: break;
  }
  return 0;
}

int compoundStatement(Ast *node,int escopo)
{
  switch(node->value)
  {
    case 267:
             /* do nothing */ 
	 return 1;
	 break;
    case 268:
             
	 statementList(node->b,escopo);
	 return 1;
	 
    case 269: 
             
             declarationList(node->b,escopo);
             return 1;
             break;
    case 270:
             declarationList(node->b,escopo);
	 statementList(node->c,escopo);
	 return 1;
	 break;
  }
  return 0;
}

int functionDefinition(Ast *node,int escopo)
{
  char *nome = 0;
  int tipo = 0;
  switch(node->value)
  {
    case 291:
              declarationSpecifiers(node->a,escopo);
	  nome = declarator(node->b,escopo);
	  declarationList(node->c,escopo);
	  compoundStatement(node->d,escopo);
	  break;
    case 292: 
              tipo = declarationSpecifiers(node->a,escopo); 
	//  novoEscopoVariaveis(&raizVariaveis,escopo+1);
	
	  nome = declarator(node->b,escopo+1); 
//	  nomefuncao = nome;
             
              #ifdef DEBUG
            printf("\n\n\n nome 292 =  %s tipo 292 = %d \n\n\n",nome,tipo);
              #endif
              if(nome != 0)
	  {
              insereFuncao(&raizFuncoes,nome,0,0,1);
	  }
	  compoundStatement(node->c,escopo+1); 
	//  printf("\n\n\n1\n\n\n\n");
	  printf("\n\n\n");
	 // imprimirTabelaVariaveis(raizVariaveis);
	  excluirEscopo(&raizVariaveis, escopo+1);
	 //  printf("\n\n\n\n2\n\n\n");
	  //deletar
	  break;
    case 293: //funcao void
              nome = declarator(node->a,escopo);
//	  nomefuncao = nome;
              // printf("\n\n\n name 293 = %s\n\n\n",nome);
              declarationList(node->b,escopo+1);
	  compoundStatement(node->c,escopo+1);
	  //printf("\n\n\n\n %s \n\n\n\n",nomefuncao);
	//    printf("\n\n\n1\n\n\n\n");
	 // imprimirTabelaVariaveis(raizVariaveis);
	  //imprimirTabelaFuncoes(raizFuncoes);
	 // imprimirTabelaParametros(raizParametros);
	  excluirEscopo(&raizVariaveis, escopo+1);
	  //nomefuncao = 0;
	  //nomefuncao = 0;
	  //   printf("\n\n\n\n2\n\n\n");
	  // deletar
	  break;
    case 294: nome=  declarator(node->a,escopo);
    #ifdef DEBUG
              printf("\n294 nome = %s ",nome);
	  #endif
	  insereFuncao(&raizFuncoes,nome,0,0,1);
              compoundStatement(node->b,escopo+1);
	  printf("\n\n\n");
             // imprimirTabelaVariaveis(raizVariaveis);
	//  excluirEscopo(&raizVariaveis, escopo+1);
	  break;
	  
  }
  return 0;
}

int externalDeclaration(Ast *node,int escopo) //pronto
{
  switch(node->value)
  {
    case 289: functionDefinition(node->a,escopo); break;
    case 290: declaration(node->a,escopo); break;
    default: break;
  }
  return 0;
}

 
int mainAst (Ast *node,int escopo) //full
{
  int semantico;
  switch(node->value)
  {
  
    case 84: externalDeclaration(node->a,escopo); break;
    case 85: mainAst(node->a,escopo); externalDeclaration(node->b,escopo); break;
    
    default: semantico = 0; break;
  }
  //printf("node %d\n",node->value);
  return 0;
}