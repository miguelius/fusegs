# fusegs

Filesystem basado en http://www.cs.nmsu.edu/~pfeiffer/fuse-tutorial/html/index.html

La idea es construir un filesystem que replique los datos en otro directorio y que permita manejar una cache en memoria de los datos de los archivos.

Para trabajar con el filesystem necesitamos un directorio físico que guardará los archivos y otro que será el directorio en el que se montará el filesystem virtual. 

Para eso se implemento un TAD diccionario (o map clave valor) y un TAD arreglo para manejar los datos que se guardan en el diccionario.

## Requerimientos

Se recomienda usar Ubuntu 14 y los siguientes requerimientos:

* build-essentials
* libfuse
* valgrind (para hacer pruebas y encontrar errores de manejo de memoria)

## Compilar

Clonar el repositorio y ejecutar:

```bash
git clone https://github.com/miguelius/fusegs
cd fusegs
make
```

## Ejecutar

Creamos los directorios físico y virtual. Luego ejecutamos:

```
./bbf directorioFisico directorioVirtual
```

En todo momento el archivo bbfs.log registrará los eventos del filesystem.

