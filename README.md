<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# TDA HASH

## Repositorio de (Nombre Apellido) - (Padrón) - (Mail)

- Para compilar:

```bash
línea de compilación
```

- Para ejecutar:

```bash
línea de ejecución
```

- Para ejecutar con valgrind:
```bash
línea con valgrind
```
---
##  Funcionamiento

Explicación de cómo funcionan las estructuras desarrolladas en el TP y el funcionamiento general del mismo.

Aclarar en esta parte todas las decisiones que se tomaron al realizar el TP, cosas que no se aclaren en el enunciado, fragmentos de código que necesiten explicación extra, etc.

Incluír **EN TODOS LOS TPS** los diagramas relevantes al problema (mayormente diagramas de memoria para explicar las estructuras, pero se pueden utilizar otros diagramas si es necesario).

### Por ejemplo:

El programa funciona abriendo el archivo pasado como parámetro y leyendolo línea por línea. Por cada línea crea un registro e intenta agregarlo al vector. La función de lectura intenta leer todo el archivo o hasta encontrar el primer error. Devuelve un vector con todos los registros creados.

<div align="center">
<img width="70%" src="img/diagrama1.svg">
</div>

En el archivo `sarasa.c` la función `funcion1` utiliza `realloc` para agrandar la zona de memoria utilizada para conquistar el mundo. El resultado de `realloc` lo guardo en una variable auxiliar para no perder el puntero original en caso de error:

```c
int *vector = realloc(vector_original, (n+1)*sizeof(int));

if(vector == NULL)
    return -1;
vector_original = vector;
```


<div align="center">
<img width="70%" src="img/diagrama2.svg">
</div>

---

## Respuestas a las preguntas teóricas
- ¿Qué es un diccionario?
    Un diccionario es una estructura de datos que permite almacenar y recuperar datos de manera eficiente, de la forma clave-valor. La clave es un identificador único que permite acceder a un valor asociado a la misma. 

<div align="center">
<img width="70%" src="img/diccionario.png">
</div>

- ¿Qué es una función de hash y qué características debe tener?
    Una función de hash es una función que permite transformar una clave en un valor de hash, normalmente es un numero asociado. Debe ser determinística, es decir, que para una misma clave siempre devuelva el mismo numero.

<div align="center">
<img width="70%" src="img/hash.png">
</div>

- ¿Qué es una tabla de Hash y los diferentes métodos de resolución de colisiones vistos (encadenamiento, probing, zona de desborde)?
    La tabla de hash es una estructura que contiene valores, donde puedo acceder a los mismos a través de una clave.
    Los diferentes métodos de resolución de colisiones son:
    - Encadenamiento: Se utiliza una lista enlazada para almacenar los elementos que colisionan.
    - Probing: Se utiliza una función de hash secundaria para calcular un nuevo índice en caso de colisión.
    - Zona de desborde: Se utiliza una zona de la tabla de hash para almacenar los elementos que colisionan.
<div align="center">
<img width="70%" src="img/tabla-hash.png">
</div>