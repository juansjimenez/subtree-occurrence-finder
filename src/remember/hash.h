#pragma once
#include "tree.h"
#include "table.h"


int hash(int* subseq, int len_subseq);
int** hash_subtrees(Node** tree, int len_tree, int tree_height, TableCell** hash_table, int table_len);
int* id_subtrees(Node** tree, int levels_from_id, int id, TableCell** hash_table, int table_len);
void nodes_in_level(Node** tree, int id, int level, int* node_values, int node_values_len);
void insert_in_table(TableCell** hash_table, int hash_table_len, int id, int hash, int table_index, int* subtree, int subtree_len);
int equal_trees(int* tree1, int len_tree1, int* tree2, int len_tree2);
void insert_in_linked_list(IDList* found_id_list, IDList* id_list_node);
