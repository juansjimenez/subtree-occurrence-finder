#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tree.h"
#include "table.h"
#include "hash.h"


Node* node_init(int ID, int value)
{
    Node* node = malloc(sizeof(Node));
    node -> ID = ID;
    node -> value = value;

    return node;
}

int myLog(int n) {
    if (n <= 1)
    {
        return 0;
    }
    else {
        return myLog(n >> 1) + 1;
    }
}

int subtree_count(int node_count) {
    int height = myLog(node_count);
    int count = 0;
    for (int i = 1; i <= height; i++)
    {
        int a = 2;
        int b = height + 1 - i;
        int result = pow(a, b) - 1;
        count = count + result;
    }
    
    return count;
}

void print_id_list(FILE* output_stream, IDList* found_id_list, int* first_print_marker) {

    if (*first_print_marker)
    {
        fprintf(output_stream, "%d", found_id_list -> ID);
        *first_print_marker = 0;
    } else
    {
        fprintf(output_stream, " %d", found_id_list -> ID);
    }
    
    if (found_id_list -> next)
    {
        print_id_list(output_stream, found_id_list -> next, first_print_marker);
    }
}

void search_query_tree(FILE* output_stream, int* tree, int tree_len, int hash, TableCell** hash_table, int hash_table_len, int table_index) {
    if (table_index == hash_table_len)
    {
        table_index = 0;
    }

    if (!hash_table[table_index])
    {
        fprintf(output_stream, "%d\n", -1);

    } else
    {
        TableCell* cell_found = hash_table[table_index];
        if (cell_found -> hash == hash && equal_trees(tree, tree_len, cell_found -> tree, cell_found -> tree_len)) {
            int* first_print_marker = malloc(sizeof(int));
            *first_print_marker = 1;
            print_id_list(output_stream, cell_found -> id_list, first_print_marker);
            fprintf(output_stream, "\n");
            free(first_print_marker);
        } else {
            if (hash_table_len == 1)
            {
                fprintf(output_stream, "%d\n", -1);
            } else
            {
                search_query_tree(output_stream, tree, tree_len, hash, hash_table, hash_table_len, table_index+1);
            } 
        }
    }
} 