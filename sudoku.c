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

    return 1;
}


List* get_adj_nodes(Node* n) {
    List* adj_nodes = createList(); // Creamos una nueva lista para los nodos adyacentes
    
    // Recorremos cada fila y columna para encontrar las casillas vacías y agregar valores
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (n->state[row][col] == 0) { // Si la casilla está vacía, agregamos nuevos nodos
                for (int val = 1; val <= 9; val++) { // Recorremos los valores posibles (1-9)
                    Node* adj_node = copy(n); // Copiamos el nodo original
                    adj_node->state[row][col] = val; // Agregamos un valor posible a la casilla vacía
                    addLast(adj_nodes, adj_node); // Agregamos el nodo adyacente a la lista
                }
                return adj_nodes; // Si encontramos una casilla vacía, retornamos la lista actual
            }
        }
    }
    return adj_nodes; // Si no encontramos casillas vacías, retornamos la lista vacía
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