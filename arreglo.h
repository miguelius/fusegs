#ifndef ARREGLO_H
#define ARREGLO_H
#include <stdlib.h>

struct  arreglo_s;
typedef struct arreglo_s *arreglo_t;

arreglo_t arreglo_new(int lentgh, size_t element_size);
void arreglo_free(arreglo_t a);

int arreglo_length(arreglo_t);
void *arreglo_elementos(arreglo_t);


#endif
