#include <string.h>
#include <stdlib.h>

#include "hash.h"

#define FACTOR_CARGA_MAXIMO 0.7
typedef struct nodo {
	char *clave;
	void *valor;
	struct nodo *siguiente;
}nodo_t;

struct hash{
	size_t capacidad;
	size_t cantidad;
	nodo_t **tabla;
};

hash_t *hash_crear(size_t capacidad)
{
	if (capacidad < 3)
		capacidad = 3;

	hash_t *hash = malloc(sizeof(hash_t));
	if (!hash)
		return NULL;
	
	hash->tabla = calloc(capacidad, sizeof(nodo_t*));
	if (!hash->tabla){
		free(hash);
		return NULL;
	}

	hash->capacidad = capacidad;
	hash->cantidad = 0;
	return hash;
}

unsigned long indice_hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    return hash;
}

void hash_redimensionar(hash_t *hash, size_t nueva_capacidad)
{
	if (!hash)
		return;

	nodo_t **tabla_nueva = calloc(nueva_capacidad, sizeof(nodo_t*));
	if (!tabla_nueva)
		return;

	for (size_t i = 0; i < hash->capacidad; i++) {
		nodo_t *nodo = hash->tabla[i];
		while (nodo) {
			nodo_t *nodo_a_mover = nodo;
			nodo = nodo->siguiente;
			size_t indice = indice_hash(nodo_a_mover->clave) % nueva_capacidad;
			nodo_a_mover->siguiente = tabla_nueva[indice];
			tabla_nueva[indice] = nodo_a_mover;
		}
	}

	free(hash->tabla);
	hash->tabla = tabla_nueva;
	hash->capacidad = nueva_capacidad;
}

bool agregar_capacidad(hash_t *hash){
	if(!hash)
		return false;
	
	size_t factor_carga = hash->cantidad / hash->capacidad;

	return factor_carga >= FACTOR_CARGA_MAXIMO;
}

/*
 * Inserta o actualiza un elemento en el hash asociado a la clave dada.
 *
 * Si la clave ya existía y se reemplaza el elemento, se almacena un puntero al
 * elemento reemplazado en *anterior, si anterior no es NULL.
 *
 * Si la clave no existía y anterior no es NULL, se almacena NULL en *anterior.
 *
 * La función almacena una copia de la clave provista por el usuario,
 *
 * Nota para los alumnos: Recordar que si insertar un elemento provoca
 * que el factor de carga exceda cierto umbral, SE DEBE AJUSTAR EL
 * TAMAÑO DE LA TABLA PARA EVITAR FUTURAS COLISIONES.
 *
 * Devuelve el hash si pudo guardar el elemento o NULL si no pudo.
 */
hash_t *hash_insertar(hash_t *hash, const char *clave, void *elemento,
		      void **anterior)
{
	if (!hash || !clave)
		return NULL;

	if (agregar_capacidad(hash)){
		// if(!hash_redimensionar(hash, hash->capacidad * 2))
		// 	return NULL;
	}
	size_t indice = indice_hash(clave) % hash->capacidad;

	print("indice: %lu\n", indice);
	return NULL;
}

void *hash_quitar(hash_t *hash, const char *clave)
{
	if (!hash)
		return NULL;

	return NULL;
}

void *hash_obtener(hash_t *hash, const char *clave)
{
	if (!hash)
		return NULL;

	return NULL;
}

bool hash_contiene(hash_t *hash, const char *clave)
{
	if (!hash)
		return NULL;

	return false;
}

size_t hash_cantidad(hash_t *hash)
{
	if (!hash)
		return 0;
	return hash->cantidad;
}

void hash_destruir(hash_t *hash)
{
	hash_destruir_todo(hash, NULL);
}

void hash_destruir_todo(hash_t *hash, void (*destructor)(void *))
{
	if (!hash)
		return;

	if(hash_cantidad(hash) == 0){
		free(hash->tabla);
		free(hash);
		return;
	}
	
	for (size_t i = 0; i < hash->capacidad; i++) {
		nodo_t *nodo = hash->tabla[i];
		while (nodo) {
			nodo_t *nodo_a_eliminar = nodo;
			nodo = nodo->siguiente;
			if (destructor)
				destructor(nodo_a_eliminar->valor);
			free(nodo_a_eliminar->clave);
			free(nodo_a_eliminar);
		}
	}

	free(hash);
}

size_t hash_con_cada_clave(hash_t *hash,
			   bool (*f)(const char *clave, void *valor, void *aux),
			   void *aux)
{
	size_t n = 0;
	if (!hash || !f)
		return n;

	return n;
}
