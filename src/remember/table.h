#pragma once


struct idlist;
typedef struct idlist IDList;

struct idlist
{
    int ID;
    IDList* next;
};

struct tablecell;
typedef struct tablecell TableCell;

struct tablecell
{
    int hash;
    int* tree;
    int tree_len;
    IDList* id_list;
    int id_list_count;
    
};

IDList* id_list_node_init(int ID);
TableCell* cell_init(int hash, int* tree, int tree_len, IDList* id_list);
TableCell** hash_table_init(int size);
void destroy_id_list(IDList* id_list);