#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

typedef struct dict_entry_s {
    const char *key;
    void *value;
    int length;
} dict_entry_s;

typedef struct dict_s {
    int len;
    int cap;
    dict_entry_s *entry;
} dict_s, *dict_t;

int dict_find_index(dict_t dict, const char *key) {
    int i = 0;
    for (; i < dict->len; i++) {
        if (!strcmp(dict->entry[i].key, key)) {
            return i;
        }
    }
    return -1;
}

arreglo_t dict_find(dict_t dict, const char *key, arreglo_t def) {
    int idx = dict_find_index(dict, key);
    if (idx == -1 ) {
       return def;
    }
    int len = dict->entry[idx].length;
    int element_size = sizeof(char);
    arreglo_t ret = arreglo_new(len, element_size);
    memcpy(arreglo_elementos(ret), dict->entry[idx].value, dict->entry[idx].length);
    return ret;
}

void dict_add(dict_t dict, const char *key, void *value, int length) {
   int idx = dict_find_index(dict, key);
   if (idx != -1) {
      dict->entry[idx].value = malloc(length*sizeof(char));
      dict->entry[idx].length = length;
      memcpy(dict->entry[idx].value, value, length); 
      return;
   }
   if (dict->len == dict->cap) {
       dict->cap *= 2;
       dict->entry = realloc(dict->entry, dict->cap * sizeof(dict_entry_s));
   }
   dict->entry[dict->len].key = strdup(key);
   dict->entry[dict->len].value = malloc(length*sizeof(char));
   dict->entry[dict->len].length = length;
   memcpy(dict->entry[dict->len].value, value, length); 
   dict->len++;
}

dict_t dict_new(void) {
    dict_s proto = {0, 10, malloc(10 * sizeof(dict_entry_s))};
    dict_t d = malloc(sizeof(dict_s));
    *d = proto;
    return d;
}

void dict_free(dict_t dict) {
    int i = 0;
    for (; i < dict->len; i++) {
        free((void *)dict->entry[i].key);
	free((void *)dict->entry[i].value);
    }
    free(dict->entry);
    free(dict);
}

