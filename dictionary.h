#ifndef	DICTIONARY_H
#define DICTIONARY_H

#include "arreglo.h"

/* Our declaration of the class my_class */
struct  dict_s;
typedef struct dict_s *dict_t;


arreglo_t dict_find(dict_t dict, const char *key, arreglo_t def);
void dict_add(dict_t dict, const char *key, void *value, int length);
dict_t dict_new(void);
void dict_free(dict_t dict);

#endif
