// Example from IBM tutorial

#include <glib.h>
// https://github.com/ajdecon/play/blob/master/c/glib/hashtable-example.c
#include <stdio.h>

int main(int argc, char *argv[]) {
    GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
    
    g_hash_table_insert(hash,"Jazzy","Cheelsse");
    g_hash_table_insert(hash,"Mr Darcy","Treats");

    printf("There are %d keys in the hash table\n",
        g_hash_table_size(hash));

    printf("Jazzy likes %s\n",g_hash_table_lookup(hash,"Jazzy"));

    g_hash_table_destroy(hash);
    return 0;
}