class TabelaEstruturas : public TabelaDeSimbolos{
  public:
    int ponteiro;
    TabelaEstruturas *prox;
};

void insereEstrutura(TabelaEstruturas **raiz, char *nome, int ponteiro)
{
  TabelaEstruturas *temp = *raiz;
  if(temp == 0)
  {
    temp = new TabelaEstruturas();
    temp->nome = nome;
    temp->ponteiro = ponteiro;
    temp->prox = 0;
    *raiz = temp;
  }
  else
  {
    while(temp->prox == 0)
    {
      temp = temp->prox;
    }
    temp->prox = new TabelaEstruturas();
    temp->prox->nome = nome;
    temp->prox->ponteiro = ponteiro;
    temp->prox->prox = 0;
  }
}