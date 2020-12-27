#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "table.h"
#include "tree.h"
#include "hash.h"


int equal_trees(int* tree1, int len_tree1, int* tree2, int len_tree2) {
    if (len_tree1 != len_tree2)
    {
        return 0;
    } else
    {
        for (int i = 0; i < len_tree1; i++)
        {
            if (tree1[i] != tree2[i])
            {
                return 0;
            }
        }
    }
    return 1;
}

int hash(int* subseq, int len_subseq) {
    int hash_value = 0;
    for (size_t i = 0; i < len_subseq; i++)
    {
        int subtree_component = subseq[i]+1;
        int index_component = i+1;
        hash_value += subtree_component * index_component;
    }
    return hash_value;
}

void insert_in_linked_list(IDList* found_id_list, IDList* id_list_node) {
    if (!found_id_list -> next)
    {
        found_id_list -> next = id_list_node;
    } else
    {
        insert_in_linked_list(found_id_list -> next, id_list_node);
    }
}

void insert_in_table(TableCell** hash_table, int hash_table_len, int id, int hash, int table_index, int* subtree, int subtree_len) {
    if (table_index == hash_table_len)
    {
        table_index = 0;
    }

    if (!hash_table[table_index])
    {
        IDList* id_list_node  = id_list_node_init(id);
        TableCell* cell = cell_init(hash, subtree, subtree_len, id_list_node);
        hash_table[table_index] = cell;
        hash_table[table_index] -> id_list_count += 1;
    } else
    {
        TableCell* cell_found = hash_table[table_index];
        
        if (cell_found -> hash == hash && equal_trees(subtree, subtree_len, cell_found -> tree, cell_found -> tree_len))
        {
            IDList* id_list_node  = id_list_node_init(id);
            insert_in_linked_list(cell_found -> id_list, id_list_node);
        } else
        {
            insert_in_table(hash_table, hash_table_len, id, hash, table_index+1, subtree, subtree_len);
        }
    }
}

int** hash_subtrees(Node** tree, int len_tree, int tree_height, TableCell** hash_table, int table_len) {
    int leaf_count = pow(2, tree_height-1);
    int iterations = len_tree - leaf_count;

    int** trees_to_free = malloc(iterations * sizeof(int*));

    for (int id = 1; id <= iterations; id++)
    {
        int node_deepness = myLog(id);
        int levels_from_id = tree_height - node_deepness;
        int* tree_to_free = id_subtrees(tree, levels_from_id, id, hash_table, table_len);
        trees_to_free[id-1] = tree_to_free;
    } 
    return trees_to_free;
}

int* id_subtrees(Node** tree, int levels_from_id, int id, TableCell** hash_table, int table_len) {
    int nodes_below_id = pow(2, levels_from_id) - 1;
    int* node_values = calloc(nodes_below_id + 1, sizeof(int));

    int first_empty = 0;
    node_values[nodes_below_id] = first_empty;

    for (int level = 1; level <= levels_from_id; level++)
    {
        int nodes_until_level = pow(2, level) - 1;

        nodes_in_level(tree, id, level, node_values, nodes_below_id);
        
        if (nodes_until_level > 1)
        {
            int hash_value = hash(node_values, nodes_until_level);
            int table_index = hash_value % table_len;

            insert_in_table(hash_table, table_len, id, hash_value, table_index, node_values, nodes_until_level);
        }
    }
    return node_values;
}

void nodes_in_level(Node** tree, int id, int level, int* node_values, int node_values_len) {
    if (level == 1)
    {   
        int first_empty = node_values[node_values_len];
        node_values[first_empty] = tree[id-1] -> value;
        node_values[node_values_len] += 1;

    } else if (level > 1)
    {
        nodes_in_level(tree, 2*id, level-1, node_values, node_values_len);
        nodes_in_level(tree, 2*id+1, level-1, node_values, node_values_len);
    }
}