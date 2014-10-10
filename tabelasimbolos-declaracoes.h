class TabelaDeSimbolos {
  public: 
    char *nome;
};

class TabelaVariaveis : public TabelaDeSimbolos{

  public: 
    int tipo;
    int ponteiro;
    int escopo;
    TabelaVariaveis *prox;
};

void insereVariavel(TabelaVariaveis **raiz, int escopo,char *nome,int tipo,int ponteiro)
{
  printf("\nInserir\n");
  printf("Insere variável %s nome\n",nome);
  TabelaVariaveis *temp = *raiz;
  if(temp == 0)
  {
    temp = new TabelaVariaveis();
    temp->escopo = escopo;
    temp->nome = nome;
    temp->tipo = tipo;
    temp->ponteiro = ponteiro;
    temp->prox = 0;
    *raiz = temp;
  }
  else
  {
    while(temp->prox != 0)
    {
      temp = temp->prox;
    }
    temp->prox = new TabelaVariaveis();
    temp->prox->escopo = escopo;
    temp->prox->nome = nome;
    temp->prox->tipo = tipo;
    temp->prox->ponteiro = ponteiro;
    temp->prox->prox = 0;
  }
  printf("Fim Inserir\n");
}

void imprimirTabelaVariaveis(TabelaVariaveis *raiz)
{
  printf("\nimprimindo variaveis\n");
   TabelaVariaveis *temp = raiz;
   if(temp == 0)
     printf("\ntabela vazia\n");
   while(temp != 0)
   {
     printf("Escopo %d Tipo %d Ponteiro %d Nome %s Prox %p\n",temp->escopo,temp->tipo,temp->ponteiro,temp->nome,temp->prox);
     temp = temp->prox;
   }
}
                   
void excluirEscopo(TabelaVariaveis **raiz, int escopo)
{
  TabelaVariaveis *temp = *raiz;
  TabelaVariaveis *temp2;
  if(temp == 0)
  {
    printf("\nescopo vazio\n");
  }
  else
  {
     if(temp->escopo == escopo)
     {
       temp2 = temp->prox;
       delete(temp);
       *raiz = temp2;
     }
     else
     {
       while(temp->prox != 0)
       {
         if(temp->prox->escopo == escopo)
         {
             //printf("\ntemp %p\ntemp prox %p,\n temp proxprox %p\n",temp,temp->prox,temp->prox->prox);
             temp2 = temp->prox;
	 temp->prox = temp->prox->prox;
	 delete(temp2);
         }
         else
         {
              temp = temp->prox; 
         }
       }
     }
  }
}

int procurarVariavel(TabelaVariaveis *raiz, char* variavel)
{
  TabelaVariaveis *temp = raiz;
  printf("\nProcura variavel\n");
  printf("variavel |%s|\n",variavel);
  if(variavel == 0 || strcmp(variavel,""))
  {
    printf("fim procura variavel\n");
    return 0;
  }
  while(temp != 0)
  {
    if(strcmp(temp->nome,variavel) == 0)
    {
      if(temp->tipo == 0)
      {
          printf("fim procura variavel\n");
        return 2;
      }
        printf("fim procura variavel\n");
      return 1;
    }
    temp = temp->prox;
  }
  printf("fim procura variavel\n");
  return 0;
}

int retornarTipoVariavel(TabelaVariaveis *raiz, char *variavel)
{
  TabelaVariaveis *temp = raiz;
  printf("\nretorna variavel\n");
  printf("variavel |%s|\n",variavel);
//  if(variavel == 0 || strcmp(variavel,""))
 // {
 //     printf("fim retorna variavel\n");
 //   return -12;
 // }
  while(temp != 0)
  {
    if(strcmp(temp->nome,variavel) == 0)
    {
        printf("fim retorna variavel\n");
      return temp->tipo + temp->ponteiro*100;
    }

    temp = temp->prox;
  }
  printf("fim retorna variavel\n");
  return -12;
}

int alteraTipo(TabelaVariaveis **raiz, char *variavel, int novoTipo,int ponteiro)
{
  TabelaVariaveis *temp = *raiz;
  if(variavel == 0)
  {
    return 0;
  }
  while(temp != 0)
  {
    if(strcmp(temp->nome,variavel) == 0)
    {
        temp->tipo = novoTipo;
        temp->ponteiro = ponteiro;
    }
    temp = temp->prox;
  }
  return 0;
}
