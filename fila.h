struct no
{
  char *dado;
  struct no *prox;
};


void inserir(struct no **raiz, char *inserido)
{
  struct no* temp = *raiz;
 // printf("\nfila inseriu -> |%s|\n",inserido);
  if(temp == 0)
  {
    // printf("if(temp == 0) true\n");
     temp = (struct no*) malloc(sizeof(struct no*));
    // printf("     temp = (struct no*) malloc(sizeof(struct no*));\n");
     temp->dado =  (char *) malloc(sizeof(inserido));//aqui
   //  printf("     temp->dado =  (char *) malloc(sizeof(inserido));\n");
     strcpy(temp->dado,inserido);
     temp->prox = 0;
     *raiz = temp;
     //     printf("\nfoi inserido|%s|\n",temp->dado);
     //     printf("\nfoi inserido|%s|\n",(*raiz)->dado);
  }
  else
  {
     //printf("if(temp == 0) false\n");
     while(temp->prox != 0)
     {
       temp = temp->prox; 
     }
     //printf("while(temp->prox != 0) false\n");
     temp->prox = (struct no*) malloc(sizeof(struct no*));
    // printf("     temp->dado =  (char *) malloc(sizeof(inserido));\n");
     temp->prox->dado =  (char *) malloc(sizeof(inserido));
     strcpy(temp->prox->dado,inserido);
     //printf("\nfoi inserido|%s|\n",temp->prox->dado);
     temp->prox->prox = 0;
  }
}

int buscar(struct no** raiz, char *buscado)
{
  struct no* temp = *raiz;
  
  if(temp == 0)
  {
     return 0;
  }
  else
  {
    while(temp != 0)
    {
      // printf("\nbuscou = |%s| - |%s|\n",temp->dado,buscado);
       if(strcmp (temp->dado,buscado) == 0)
       {
         return 1;
       }
       temp = temp->prox;
    }
    return 0;
  }
}


void imprimir(struct no* raiz)
{
  struct no* temp = raiz;
  if(temp == 0)
  {
     printf("vazio");
  }
  else
  {
    while(temp != 0)
    {
        printf("\n%s",temp->dado);
       temp = temp->prox;
    }
  }
}