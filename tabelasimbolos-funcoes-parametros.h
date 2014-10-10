 
class TabelaParametros : public TabelaVariaveis{
  public:
  char *funcao;
  int ordem;
  TabelaParametros *next;

};

void novoParametro(TabelaParametros **raiz,char *funcao,int ordem ,char *nome, int tipo, int ponteiro)
{
  TabelaParametros *temp = *raiz;
  if(temp == 0)
  {
    temp = new TabelaParametros();
    temp->funcao = funcao;
    temp->ordem = ordem;
    temp->nome = nome;
    temp->tipo = tipo;
    temp->ponteiro = ponteiro;
    temp->next  = 0;
    *raiz = temp;
  }
  else
  {
    while(temp->next != 0)
    {
      temp = temp->next;
    }
    temp->next = new TabelaParametros();
    temp->next->funcao = funcao;
    temp->next->ordem = ordem;
    temp->next->nome = nome;
    temp->next->tipo = tipo;
    temp->next->ponteiro = ponteiro;
    temp->next->next  = 0;
  }
}

int procurarParametroDaFuncao(TabelaParametros *raiz, char *funcao, char *nome, int ordem)
{
  TabelaParametros *temp = raiz;
  if(nome == 0)
  {
    return 0;
  }
  while(temp != 0)
  {
    if(strcmp(temp->funcao,funcao) == 0)
    {
      if(strcmp(temp->nome,nome) == 0)
      {
        if(temp->ordem == ordem)
        {
          return 1;
        }
        return -55; //sim mais fora de ordem
      }
      
    }
    temp = temp->next;
  }
  return 0;
}

int imprimirTabelaParametros(TabelaParametros *raiz)
{
  TabelaParametros *temp = raiz;
  printf("\nimprimindo paramentros\n");
  if(temp == 0)
    printf("tabela parametros vazia");
  while(temp != 0)
  {
    printf("\nParametro '%s' pertencente a funcao %s na ordem %d tipo %d ponteiro %d\n",temp->nome,temp->funcao,temp->ordem,temp->tipo,temp->ponteiro);
    temp = temp->next;
  }
}