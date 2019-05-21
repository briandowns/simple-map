#ifndef _MAP_H
#define _MAP_H

/**
 * contains the default size of a map.
 */
#define DEFAULT_SIZE 16

/**
 * returned when creating a new map and the provided 
 * size is smaller than the defined default.
 */
#define ERR_SMALLER_THAN_DEFAULT 2

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
 * map_t contains an array of nodes with a length 
 * and a capacity.
 */
typedef struct {
    int len;
    int cap;
    struct node **list;
} map_t;                  

/**
 * map_new creates a new pointer with default values
 * set for a new map. This will need to be freed
 * by the caller. If malloc(3) fails, an error will
 * be returned indicating no memory was able to be 
 * allocated.
 */
map_t *map_new(const unsigned int size);

/**
 * map_free frees the memory used by the given pointer.
 */
void map_free(map_t *m);

/**
 * map_get retrieves the value for the given key.
 */
void *map_get(map_t *m, char *key);

/**
 * map_set takes a key and a value and sets them 
 * in the map.
 */
int map_set(map_t *m, char *key, void *val);

/**
 * map_del removes an entry the given key and value 
 * from the map.
 */
void map_del(map_t *m, char *key);

#endif /* _MAP_H */
