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
  int *valido, i, j, p;
 int row, col;
   // Validamos las filas
    for (row = 0; row < 9; row++) {
        int nums[10] = {0};
        for (col = 0; col < 9; col++) {
            int num = n->sudo[row][col];
            if (num == 0) continue;
            if (nums[num]) return 0;
            nums[num] = 1;
        }
    }
    // Validamos las columnas
    for (col = 0; col < 9; col++) {
        int nums[10] = {0};
        for (row = 0; row < 9; row++) {
            int num = n->sudo[row][col];
            if (num == 0) continue;
            if (nums[num]) return 0;
            nums[num] = 1;
        }
    }
  for (subgrid = 0; subgrid < 9; subgrid++) {
        int nums[10] = {0};
        for (int p = 0; p < 9; p++) {
            row = 3 * (subgrid / 3) + (p / 3);
            col = 3 * (subgrid % 3) + (p % 3);
            int num = n->sudo[row][col];
            if (num == 0) continue;
            if (nums[num]) return 0;
            nums[num] = 1;
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
               Node* nodo = copy(n);
               for(int valor=1;valor<=9;valor++){
                   nodo->sudo[i][j] = valor;
                   if(is_valid(nodo))
                   {
                    pushBack(lista, nodo);
                    nodo = copy(nodo);
                   }
               }
               free(nodo);
               break;
           }
       }
     if(n->sudo[i][j]==0)
       break;
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