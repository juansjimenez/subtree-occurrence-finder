#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"
#include "table.h"
#include "hash.h"


int main(int argc, char** argv)
{
  if(argc != 3)
  {
    printf("Modo de uso: %s input output\nDonde:\n", argv[0]);
    printf("\t\"input\" es la ruta al archivo de input\n");
    printf("\t\"output\" es la ruta al archivo de output\n");
    return 1;
  }

  // Abrimos el archivo de input
  FILE* input_stream = fopen(argv[1], "r");

  // Abrimos el archivo de output
  FILE* output_stream = fopen(argv[2], "w");

  // Si alguno de los dos archivos no se pudo abrir
  if(!input_stream)
  {
    printf("El archivo %s no existe o no se puede leer\n", argv[1]);
    return 2;
  }
  if(!output_stream)
  {
    printf("El archivo %s no se pudo crear o no se puede escribir\n", argv[2]);
    printf("Recuerda que \"fopen\" no puede crear carpetas\n");
    fclose(input_stream);
    return 3;
  }

  // Se lee el arbol principal
  int node_count;
  fscanf(input_stream, "%d", &node_count);
  Node** tree_nodes = malloc(node_count * sizeof(Node*));
  for (int i = 1; i <= node_count; i++)
  {
    int id = i;
    int value;
    fscanf(input_stream, "%d", &value);
    Node* node = node_init(id, value);
    tree_nodes[i-1] = node; 
  }
  
  // Con el arbol guardado, se genera la tabla de hash
  int table_length = subtree_count(node_count);
  TableCell** hash_table = hash_table_init(table_length);

  int tree_height = myLog(node_count)+1;

  // Se encuentran los subarboles, se hashean y se insertan en la hash table.
  int** trees_to_free = hash_subtrees(tree_nodes, node_count, tree_height, hash_table, table_length);

  // Se leen las consultas
  int query_count;
  fscanf(input_stream, "%d", &query_count);
  for (int i = 0; i < query_count; i++)
  {
    int query_node_count;
    fscanf(input_stream, "%d", &query_node_count);

    int* query_tree = malloc(query_node_count * sizeof(int));
    
    for (int i = 0; i < query_node_count; i++)    
    {
      int value;
      fscanf(input_stream, "%d", &value);
      query_tree[i] = value;
    }

    int hash_value = hash(query_tree, query_node_count);
    int table_index = hash_value % table_length;

    search_query_tree(output_stream, query_tree, query_node_count, hash_value, hash_table, table_length, table_index);
    
    free(query_tree);
  }

  // Free de todas las posiciones dentro de la tabla, para cada una free de la linked list, free del tree, free de la posicion en si, despues free de la tabla en si.
  // Free de cada posicion del array que guarda el arbol general, despues free del array en si.
  int leaf_count = pow(2, tree_height-1);
  int trees_to_free_count = node_count - leaf_count;

  for (int i = 0; i < trees_to_free_count; i++)
  {
    free(trees_to_free[i]);
  }

  free(trees_to_free);



    
  for (int i = 0; i < table_length; i++)
  {
    TableCell* cell = hash_table[i];
    if (cell)
    {
      destroy_id_list(cell -> id_list);
      // free(cell -> tree);
      free(cell);
    }
  }

  free(hash_table);


  for (int i = 0; i < node_count; i++)
  {
    free(tree_nodes[i]);
  }

  free(tree_nodes);

  // Cerrar archivo de input
  fclose(input_stream);

  // Cerrar archivo de output
  fclose(output_stream);

  return 0;
}
