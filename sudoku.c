#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  int *valido= calloc(sizeof(int),10), i, j, p;

  for(i=0;i<9;i++)
  {
      for(j=0;j<9;j++)
      {           
        if(n->sudo[i][j] !=0)
        {
          if(n->sudo[i][j] > 9 || valido[n->sudo[i][j]] == 1)
            return 0;
          else
            valido[n->sudo[i][j]] = 1;
        }
      }
  }
  for(j=0;j<9;j++)
  {           
    if(n->sudo[j][i] > 9 || valido[n->sudo[j][i]] == 1)
      return 0;
    else
      valido[n->sudo[j][i]] = 1;
  }

  for(int k=0 ; k<9 ; k++)
  {
    valido = calloc(sizeof(int),10);
    for(p=0;p<9;p++){
      i=3*(k/3) + (p/3) ;
      j=3*(k%3) + (p%3) ;
      if(n->sudo[i][j] > 9 || valido[n->sudo[i][j]] == 1)
        return 0;
      else
        valido[n->sudo[i][j]] = 1;
    }
    free(valido);
  }
  free(valido);
  return 1;
}



List* get_adj_nodes(Node* n){
   List* lista = createList();
   int i, j;
   for(i=0; i<9; i++){
       for(j=0; j<9; j++){
           if(n->sudo[i][j]==0){
               for(int valor=1; valor<=9; valor++){
                   Node* nodo = copy(n);
                   nodo->sudo[i][j] = valor;
                   if(is_valid(nodo)) {
                       pushBack(lista, nodo);
                   } else {
                       free(nodo);
                   }
               }
               break;
           }
       }
     if(n->sudo[i][j]==0)
       break;
   }
   return lista;
}


int is_final(Node* n){
  for(int i = 0 ; i < 9 ; i++)
    for(int j = 0 ; j < 9 ; j++)
      if(n->sudo[i][j]==0)
        return 0;
  return 1;
}

Node* DFS(Node* initial, int* cont){
  Stack* S = createStack();

  push(S, initial);
  while(top(S)!=NULL)
  {
    Node *auxEstado = top(S);
    pop(S);
    if(is_final(auxEstado))
      return auxEstado;

    List *listaNodosAdj = get_adj_nodes(auxEstado);
    for(Node *auxNodo = first(listaNodosAdj); auxNodo!=NULL ; auxNodo = next(listaNodosAdj))
    {
      push(S, auxNodo); 
    }

    free(auxEstado);
    (*cont)++;
  }

  
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/