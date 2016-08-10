#include "arreglo.h"

typedef struct arreglo_s {
    int length;
    void *elementos;
} arreglo_s, *arreglo_t;

arreglo_t arreglo_new(int length, size_t element_size) {
  arreglo_t ret = malloc(sizeof(arreglo_s));
  ret->length = length;
  ret->elementos = malloc(length * element_size);
  return ret;
}

int arreglo_length(arreglo_t a) {
  return a->length;
}

void *arreglo_elementos(arreglo_t a) {
  return a->elementos;
}

void arreglo_free(arreglo_t a) {
  if (a->length>0) {
     free(a->elementos);
  }
  free(a);
} 


