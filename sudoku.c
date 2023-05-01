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
  int *valido, i, j, z;
  for(i=0;i<9;i++)
  {
    valido = calloc(sizeof(int),10);
       for(j=0;j<9;j++)
       {
         for(z = 0; z < 9; z++)
            if(is_valid(n) == valido[z])
              return 1;
           
         if(n->sudo[i][j] !=0)
         {
           if(valido[n->sudo[i][j]] == 1  || valido[n->sudo[j][i]] == 1)
             return 0;
           else
             valido[n->sudo[i][j]] = 1;
         }
       }
    /*for(p=0;p<9;p++){
      int i=3*(k/3) + (p/3) ;
      int j=3*(k%3) + (p%3) ;
      if(p%3 == 2) 
    }*/
}
    
  }
  return 1;
}


List* get_adj_nodes(Node* n){
   List* lista=createList();
   int i, j;
   for(i=0;i<9;i++){
       for(j=0;j<9;j++){
           if(n->sudo[i][j]==0){
               for(int valor=1;valor<=9;valor++){
                   Node* nodo = copy(n);
                   nodo->sudo[i][j] = valor;
                   pushBack(lista, nodo);
               }
               break;
           }
       }
       if(n->sudo[i][j]==0) break;
   }
   return lista;
}

int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
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