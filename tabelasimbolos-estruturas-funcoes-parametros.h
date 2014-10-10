class TabelaParametrosFuncoesEstruturas : public TabelaParametros{
  public:
  char *estrutura;
  TabelaParametrosFuncoesEstruturas *dir;
};

void novoParametroEstrutura(TabelaParametrosFuncoesEstruturas **raiz,char *funcao,int ordem ,char *nome, int tipo, int ponteiro, char *estrutura)
{
  
  TabelaParametrosFuncoesEstruturas *temp = *raiz;
  if(temp == 0)
  {
    temp = new TabelaParametrosFuncoesEstruturas();
    temp->funcao = funcao;
    temp->ordem = ordem;
    temp->nome = nome;
    temp->tipo = tipo;
    temp->ponteiro = ponteiro;
    temp->estrutura = estrutura;
    temp->dir  = 0;
    *raiz = temp;
  }
  else
  {
    while(temp->dir != 0)
    {
      temp = temp->dir;
    }
    temp->dir = new TabelaParametrosFuncoesEstruturas();
    temp->dir->funcao = funcao;
    temp->dir->ordem = ordem;
    temp->dir->nome = nome;
    temp->dir->tipo = tipo;
    temp->dir->ponteiro = ponteiro;
    temp->dir->next  = 0;
  }
}