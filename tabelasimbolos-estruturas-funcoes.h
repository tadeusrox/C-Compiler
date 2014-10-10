class TabelaFuncoesEstruturas : public TabelaFuncoes{
  public: 
  char *estrutura;
  TabelaFuncoesEstruturas *next;
};

int procurarFuncaoEstrutura(TabelaFuncoesEstruturas *raiz, char *funcao, char *estrutura)
{
  TabelaFuncoesEstruturas *temp = raiz;
  if(temp == 0)
    return 0;
  while(temp != 0)
  {
    if(strcmp(temp->nome,funcao) == 0 && strcmp(temp->estrutura,estrutura) == 0)
    {
      if(temp->implementada == 1)
      {
        return 1;
      }
      else
        return 2;
    }
  }
}

void insereFuncaoEstrutura(TabelaFuncoesEstruturas **raiz, char *nome, int tipo, int ponteiro, int implementada, char *estrutura)
{

  TabelaFuncoesEstruturas *temp = *raiz;
  if(temp == 0)
  {
    temp = new TabelaFuncoesEstruturas();
    temp->nome = nome;
    temp->tipo = tipo;
    temp->ponteiro = ponteiro;
    temp->estrutura = estrutura;
    temp->next = 0;
    *raiz = temp;
  }
  else
  {
    while(temp->next != 0)
    {
      temp = temp->next;
    }
    temp->next = new TabelaFuncoesEstruturas();
    temp->next->nome = nome;
    temp->next->tipo = tipo;
    temp->next->ponteiro = ponteiro;
    temp->next->estrutura = estrutura;
    temp->next->next = 0;
  }
}

int retornarTipoFuncaoEstrutura(TabelaFuncoesEstruturas *raiz, char *funcao, char *estrutura)
{
  TabelaFuncoesEstruturas *temp = raiz;
  if(funcao == 0 || estrutura == 0)
  {
    return -12;
  }
}