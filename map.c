#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"

void
node_free(struct node *n) 
{
    if (!n) {
        return;
    }
    free(n->key);
    free(n->next);
    free(n);
}

struct map*
map_new(const int size)
{
    struct map *m = malloc(sizeof(struct map));
    if (!m) {
        return NULL;
    }
    memset(m, 0, sizeof(struct map));
    if (size == 0) {
        m->cap = DEFAULT_SIZE;    
    } else {
        m->cap = size;
    }
    m->len = 0;
    m->list = malloc(sizeof(struct node*)*m->cap); 
    if (m->list == NULL) {
        return NULL;
    }
    for (int i = 0; i < m->cap; i++) {
        m->list[i] = NULL;
    }
    return m;
}

void
map_free(struct map *m) {
    if (!m) {
        return;
    }
    if (m->list) {
        free(m->list);
    }
    free(m);
}

/**
 * hash hashes the given string to find which
 * bucket it will be placed in.
 */
static int
hash(struct map *m, char *key)
{
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % m->cap;
}

void*
map_get(struct map *m, char *key)
{
    int pos = hash(m, key);
    struct node *list = m->list[pos];
    struct node *temp = list;
    while (temp) {
        if (strcmp(temp->key, key) == 0) {
            return temp->val;
        }
        temp = temp->next;
    }
    return NULL;
}

void
map_set(struct map *m, char *key, void *val)
{
    int pos = hash(m, key);              
    struct node *list = m->list[pos]; 
    struct node *temp = list;                      
    while (temp) {                 
        if (strcmp(temp->key, key) == 0) {
            temp->val = val;
            return;
        }
        temp = temp->next;
    }
    struct node *new = malloc(sizeof(struct node)); 
    if (!new) {                                     
        return;                                    
    }
    memset(new, 0, sizeof(struct node));
    new->key = strdup(key);
    new->val = val;
    new->next = list;
    m->list[pos] = new;
    m->len++;
}

void
map_del(struct map *m, char *key) {
    int pos = hash(m, key);
    struct node **n = &m->list[pos];
    while (*n) {
        struct node *temp = *n; 
        if (strcmp(temp->key, key) == 0) {
            *n = temp->next;
            break;
        } else {
            temp = (*n)->next;
        }
    }  
    m->len--;       
    return;
}

int 
map_len(struct map *m) 
{
    int items = 0;
    for (int i = 0; i < m->cap; i++) {
        if (!m->list[i]) {
            items++;
        }
    }
    return items;
}
