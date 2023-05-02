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

int is_valid(Node * n){
    int row, col, subgrid;
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
    // Validamos las submatrices
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
    List* list = createList();
    int row, col;
    // Buscamos la primer casilla vacía
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (n->sudo[row][col] == 0) {
                // Creamos una copia del nodo
                Node* new_node = copy(n);
                // Probamos los valores del 1 al 9
                for (int val = 1; val <= 9; val++) {
                    new_node->sudo[row][col] = val;
                    // Si el nuevo nodo es válido, lo agregamos a la lista
                    if (is_valid(new_node)) {
                        pushBack(list, new_node);
                        // Creamos un nuevo nodo para la siguiente iteración
                        new_node = copy(new_node);
                    }
                }
                // Liberamos la memoria del nuevo nodo que no se agregó a la lista
                destroyNode(&new_node);
                // Como ya encontramos la primer casilla vacía, salimos del ciclo
                goto finish;
            }
        }
    }
    finish:
    return list;
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