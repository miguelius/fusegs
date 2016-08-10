#include <stdio.h>
#include "dictionary.h"

int main(int argc, char *argv[]) {
   dict_t d = dict_new();
   arreglo_t a;
   dict_add(d, "saludo", "hola, mundo!", strlen("hola, mundo!")+1);
   a = dict_find(d, "saludo",NULL);
   if (a != NULL) {
     printf("%d:%s",a->length, a->elementos);
     
   }
   dict_free(d);
   return 0;
}
