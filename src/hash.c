#include <string.h>
#include <stdlib.h>

#include "hash.h"

#define FACTOR_CARGA_MAXIMO 0.7

typedef struct nodo {
	char *clave;
	void *valor;
	struct nodo *siguiente;
}nodo_t;

typedef struct {
	size_t capacidad;
	size_t cantidad;
	nodo_t **tabla;
} hash_t;

hash_t *hash_crear(size_t capacidad)
{
	if (capacidad < 3)
		capacidad = 3;

	hash_t *hash = malloc(sizeof(hash_t));
	if (!hash)
		return NULL;
	
	hash->tabla = malloc(sizeof(nodo_t*) * capacidad);
	if (!hash->tabla){
		free(hash);
		return NULL;
	}

	hash->capacidad = capacidad;
	hash->cantidad = 0;
	return hash;
}

hash_t *hash_insertar(hash_t *hash, const char *clave, void *elemento,
		      void **anterior)
{
	if (!hash || !clave)
		return NULL;

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
	return 0;
}

void hash_destruir(hash_t *hash)
{
	hash_destruir_todo(hash, NULL);
}

void hash_destruir_todo(hash_t *hash, void (*destructor)(void *))
{
	if (!hash)
		return;

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
