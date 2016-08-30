# fusegs

Filesystem basado en http://www.cs.nmsu.edu/~pfeiffer/fuse-tutorial/html/index.html

La idea es construir un filesystem que replique los datos en otro directorio y que permita manejar una cache en memoria de los datos de los archivos.

Para eso se implemento un TAD diccionario (o map clave valor) y un TAD arreglo para manejar los datos que se guardan en el diccionario.

## Requerimientos

Se recomienda usar Ubuntu 14 y los siguientes requerimientos:

* build-essentials
* libfuse
* valgrind (para hacer pruebas)

## Compilar

Clonar el repositorio y ejecutar:

```bash
make
```

## Ejecutar

```
bbf directorioFisico directorioVirtual
```

