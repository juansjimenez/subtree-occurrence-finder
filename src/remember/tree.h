#pragma once
#include "table.h"


struct node;
typedef struct node Node;

struct node
{
    int ID;
    int value;
};

Node* node_init(int ID, int value);
int subtree_count(int node_count);
int myLog(int n);
void search_query_tree(FILE* output_stream, int* tree, int tree_len, int hash, TableCell** hash_table, int hash_table_len, int table_index);
void print_id_list(FILE* output_stream, IDList* found_id_list, int* print_marker);