#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "table.h"
#include "tree.h"


IDList* id_list_node_init(int ID) {
    IDList* id_list = malloc(sizeof(IDList));
    id_list -> ID = ID;
    id_list -> next = NULL;

    return id_list;
}

TableCell* cell_init(int hash, int* tree, int tree_len, IDList* id_list) {
    TableCell* table_cell = malloc(sizeof(TableCell));
    table_cell -> hash = hash;
    table_cell -> tree = tree;
    table_cell -> tree_len = tree_len;
    table_cell -> id_list = id_list;
    table_cell -> id_list_count = 0;

    return table_cell;
}

TableCell** hash_table_init(int size) {
    TableCell** hash_table = calloc(size, sizeof(TableCell*));
    
    return hash_table;
}

// void destroy_id_list(IDList* id_list) {
//     if (!id_list -> next)
//     {
//         free(id_list);
//     } else
//     {
//         destroy_id_list(id_list -> next);
//         id_list -> next = NULL;
//         free(id_list);
//     }
// }


void destroy_id_list(IDList* id_list) {
    IDList* temp;
    while (id_list)
    {
        temp = id_list;
        id_list = id_list -> next;
        free(temp);
    }
}