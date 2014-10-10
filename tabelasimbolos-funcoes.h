class TabelaFuncoes : public TabelaDeSimbolos {
  public: 
    int tipo;
    int ponteiro;
    int implementada;
    TabelaFuncoes *prox; 
};

int procurarFuncao(TabelaFuncoes *raiz, char *funcao)
{
  TabelaFuncoes *temp = raiz;
  if(temp == 0)
    return 0;
  while(temp != 0)
  {
    if(strcmp(temp->nome,funcao) == 0)
    {
      if(temp->implementada == 1)
      {
        return 1;
      }
      else
        
        return 2;
    }
    temp = temp->prox;
  }
  return 0;
}


void insereFuncao(TabelaFuncoes **raiz, char *nome, int tipo, int ponteiro, int implementada)
{
  TabelaFuncoes *temp = *raiz;
  if(temp == 0)
  {
    temp = new TabelaFuncoes();
    temp->nome = nome;
    temp->tipo = tipo;
    temp->ponteiro = ponteiro;
    temp->implementada = implementada;
    temp->prox = 0;

    *raiz = temp;
  }
  else
  {
    while(temp->prox != 0)
    {
      temp = temp->prox;
    }
    temp->prox = new TabelaFuncoes();
    temp->prox->nome = nome;
    temp->prox->tipo = tipo;
    temp->prox->ponteiro = ponteiro;
    temp->prox->implementada = implementada;
    temp->prox->prox = 0;
  }
}

void imprimirTabelaFuncoes(TabelaFuncoes *raiz)
{
  TabelaFuncoes *temp = raiz;
  printf("\nImprimindo tabela funcoes\n");
  if(temp == 0)
    printf("tabela funcoes vazia");
  while(temp != 0)
  {
    printf("Funcao %s Tipo %d Ponteiro %d Implementada %d Prox %p\n",temp->nome,temp->tipo,temp->ponteiro,temp->implementada,temp->prox);
    temp = temp->prox;
  }
}


int retornarTipoFuncao(TabelaFuncoes *raiz, char *funcao)
{
  TabelaFuncoes *temp = raiz;
  if(funcao == 0)
    return -12;
  while(temp != 0)
  {
    if(strcmp(temp->nome,funcao) == 0)
    {
      return temp->tipo + temp->ponteiro*100;
    }
    temp = temp->prox;
  }
  return -12;
}