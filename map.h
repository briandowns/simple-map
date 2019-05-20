#ifndef _MAP_H
#define _MAP_H

/**
 * DEFAULT_SIZE contains the default size of a map
 */
#define DEFAULT_SIZE 16

/**
 * node contains the key and the associated value
 * along with a pointer to the next node.
 */
struct node {
    char *key;
    void *val;
    struct node *next;
};

/**
 * map contains an array of nodes with a length 
 * and a capacity.
 */
struct map {
    int cap;
    int len;
    struct node **list;
};                  

/**
 * map_new creates a new pointer with default values
 * set for a new map. This will need to be freed
 * by the caller.
 */
struct map *map_new(const int size);

/**
 * map_free frees the memory used by the given pointer.
 */
void map_free(struct map *m);

/**
 * map_get retrieves the value for the given key.
 */
void *map_get(struct map *m, char *key);

/**
 * map_set takes a key and a value and sets them 
 * in the map.
 */
void map_set(struct map *m, char *key, void *val);

/**
 * map_del removes an entry the given key and value 
 * from the map.
 */
void map_del(struct map *m, char *key);

#endif /* _MAP_H */
