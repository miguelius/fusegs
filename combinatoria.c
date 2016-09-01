#include <stdio.h>
#include <pthread.h>

#include <unistd.h>     // para hacer sleep
#include <stdlib.h>     // para libreria de numeros random: srand, rand 
#include <semaphore.h>
#include <time.h>       // para tomar el tiempo 

#define NUM_THREADS 3
sem_t semaforo;
double x = 1, y = 1;

void* denominador(void* parametro)
{   
   printf("Calculando el denominador...\n");
   int *nk = (int *)parametro;
   
   int i = nk[1];

   for(; i >= 1; i--)
   {
        x *= i*1.0;
   }

   sem_post(&semaforo);
   printf("Denominador calculado!\n");
   pthread_exit(NULL);
}

void* numerador(void* parametro)
{   
   printf("Calculando el numerador...\n");
   int *nk = (int *)parametro;
   int i = nk[0]; 
   int hasta = nk[0] - nk[1];
   for(; i > hasta; i--)
   {
         y *= i*1.0;
   }
   sem_post(&semaforo);
   printf("Numerador calculado!\n"); 
   pthread_exit(NULL);
}

void* calcular(void* parametro)
{   
   int *nk = (int *)parametro;
   
   printf("Esperando al denominador y al numerador\n");
   sem_wait(&semaforo);
   sem_wait(&semaforo);

   printf("Denominador y numerador listos!\n");

   printf("(%d %d) = %0.f \n", nk[0], nk[1], y/x);
   
   pthread_exit(NULL);
}


void *funciones[] = {calcular, numerador, denominador};

int main (int argc, const char *argv[])
{
   pthread_t threads[NUM_THREADS]; //una variable de tipo pthread_t sirve para identificar cada hilo que se cree
                                   //la variable threads es una array de pthread_t
                                   //comparar con char data[100], un array de char                                           
   int rc;
   int i = 0;

   if (argc != 3) {
	  printf("uso:%s n k\n", argv[0]);
	  exit(0);
   }
   
   int ret_init = sem_init(&semaforo, 0, 0);
   if (ret_init != 0) {
	perror("sem_init failed");
	exit(-1);
   }
   int parametros[2];
   int n = atoi(argv[1]);
   int k = atoi(argv[2]);

   parametros[0] = n; parametros[1] = k;   

   pthread_attr_t custom_sched_attr;	
   pthread_attr_init(&custom_sched_attr);	
   pthread_attr_setschedpolicy(&custom_sched_attr, SCHED_RR);	
   for (;i<NUM_THREADS; ++i) {
	   rc = pthread_create(&threads[i],        	//identificador unico
				  &custom_sched_attr,            	//atributos del thread
				  funciones[i],    	//funcion a ejecutar 
				  (void *) parametros); //parametros de la funcion a ejecutar, pasado por referencia
	   if (rc){
		 printf("Error:unable to create thread, %d \n", rc);
		 exit(-1);
	   }
   }
	
    for(int i = 0 ; i < NUM_THREADS ; i++)
    {
        pthread_join(threads[i] , NULL);
    }

   pthread_exit(NULL);
}


