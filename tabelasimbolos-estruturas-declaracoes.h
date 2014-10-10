class TabelaVariaveisEstruturas : public TabelaVariaveis{
  public:
    char *estrutura;
    TabelaVariaveisEstruturas *next;
};


void insereVariavel(TabelaVariaveisEstruturas **raiz, int escopo,char *nome,int tipo,int ponteiro, char *estrutura)
{
  TabelaVariaveisEstruturas *temp = *raiz;
  if(temp == 0)
  {
    temp = new TabelaVariaveisEstruturas();
    temp->escopo = escopo;
    temp->nome = nome;
    temp->tipo = tipo;
    temp->ponteiro = ponteiro;
    temp->estrutura = estrutura;
    temp->next = 0;
    *raiz = temp;
  }
  else
  {
    while(temp->prox != 0)
    {
      temp = temp->next;
    }
    temp->next = new TabelaVariaveisEstruturas();
    temp->next->escopo = escopo;
    temp->next->nome = nome;
    temp->next->tipo = tipo;
    temp->next->ponteiro = ponteiro;
    temp->next->estrutura = estrutura;
    temp->next->next = 0;
  }
}