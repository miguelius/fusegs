#include <stdio.h>
#include "dictionary.h"

int main(int argc, char *argv[]) {
   dict_t d = dict_new();
   arreglo_t a;
   dict_add(d, "saludo", "hola, mundo!", strlen("hola, mundo!")+1);
   dict_add(d, "despedida", "adios mundo cruel!", strlen("adios mundo cruel!")+1);
   a = dict_find(d, "saludo",NULL);
   if (a != NULL) {
     printf("%d:%s",arreglo_length(a), (char *)arreglo_elementos(a));
   }
   arreglo_free(a);
   a = dict_find(d, "despedida",NULL);
   if (a != NULL) {
     printf("%d:%s",arreglo_length(a), (char *)arreglo_elementos(a));
   }
   arreglo_free(a);
   dict_free(d);
   return 0;
}
