#include "pa2m.h"
#include "src/hash.h"
#include <stdio.h>
#include <string.h>

void prueba_crear()
{
	size_t capac = 3;
	hash_t *hash = hash_crear(capac);
	pa2m_afirmar(hash != NULL, "Prueba crear un hash con capacidad 3");
	hash_destruir(hash);

	hash = hash_crear(10);
	pa2m_afirmar(hash != NULL, "Prueba crear un hash con capacidad 10");
	hash_destruir(hash);

	hash = hash_crear(100);
	pa2m_afirmar(hash != NULL, "Prueba crear un hash con capacidad 100");
	hash_destruir(hash);

	hash = hash_crear(2);
	pa2m_afirmar(
		hash != NULL,
		"Prueba crear un hash con capacidad 2 y lo crea con capacidad 3");
	hash_destruir(hash);
}

void prueba_insertar()
{
	hash_t *hash = hash_crear(5);
	char *clave1 = "clave1";
	char *clave2 = "clave2";
	char *clave3 = "clave3";
	char *clave4 = "clave4";
	char *clave5 = "clave5";

	char *valor1 = "valor1";
	char *valor2 = "valor2";
	char *valor3 = "valor3";
	char *valor4 = "valor4";
	char *valor5 = "valor5";

	pa2m_afirmar(hash_insertar(NULL, clave1, valor1, NULL) == NULL,
		     "No se puede insertar en un hash NULL");

	pa2m_afirmar(hash_insertar(hash, NULL, valor1, NULL) == NULL,
		     "No se puede insertar una clave NULL");

	pa2m_afirmar(
		hash_insertar(hash, clave1, valor1, NULL) == hash &&
			hash_cantidad(hash) == 1,
		"Se inserta clave1 con valor1 y se obtiene la clave1 con valor1");
	pa2m_afirmar(hash_cantidad(hash) == 1, "La cantidad es 1");

	pa2m_afirmar(
		hash_insertar(hash, clave2, valor2, NULL) == hash &&
			hash_cantidad(hash) == 2,
		"Se inserta clave2 con valor2 y se obtiene la clave2 con valor2");
	pa2m_afirmar(hash_cantidad(hash) == 2, "La cantidad es 2");

	pa2m_afirmar(
		hash_insertar(hash, clave3, valor3, NULL) == hash &&
			hash_cantidad(hash) == 3 &&
			hash_obtener(hash, clave3) == valor3,
		"Se inserta clave3 con valor3 y se obtiene la clave3 con valor3");
	pa2m_afirmar(hash_cantidad(hash) == 3, "La cantidad es 3");

	pa2m_afirmar(
		hash_insertar(hash, clave3, valor4, NULL) == hash &&
			hash_cantidad(hash) == 3 &&
			hash_obtener(hash, clave3) == valor4,
		"Se inserta clave3 con valor4 y se obtiene la clave3 con valor4");
	pa2m_afirmar(
		hash_cantidad(hash) == 3,
		"La cantidad sigue siendo 3, se actualiza el valor de la clave");

	pa2m_afirmar(
		hash_insertar(hash, clave4, valor4, NULL) == hash &&
			hash_cantidad(hash) == 4 &&
			hash_obtener(hash, clave4) == valor4,
		"Se inserta clave4 con valor4 y se obtiene la clave4 con valor4");
	pa2m_afirmar(hash_cantidad(hash) == 4, "La cantidad es 4");

	pa2m_afirmar(
		hash_insertar(hash, clave5, valor5, NULL) == hash &&
			hash_cantidad(hash) == 5 &&
			hash_obtener(hash, clave5) == valor5,
		"Se inserta clave5 con valor5 y se obtiene la clave5 con valor5");
	pa2m_afirmar(hash_cantidad(hash) == 5, "La cantidad es 5");

	pa2m_afirmar(
		hash_insertar(hash, clave5, valor1, NULL) == hash &&
			hash_cantidad(hash) == 5 &&
			hash_obtener(hash, clave5) == valor1,
		"Se inserta clave5 con valor1 y se obtiene la clave5 con valor1");
	pa2m_afirmar(
		hash_cantidad(hash) == 5,
		"La cantidad sigue siendo 5, se actualiza el valor de la clave");

	hash_destruir(hash);
}

void prueba_eliminar()
{
	hash_t *hash = hash_crear(5);
	char *clave1 = "clave1";
	char *clave2 = "clave2";
	char *clave3 = "clave3";

	char *valor1 = "valor1";
	char *valor2 = "valor2";
	char *valor3 = "valor3";

	hash_insertar(hash, clave1, valor1, NULL);
	hash_insertar(hash, clave2, valor2, NULL);
	hash_insertar(hash, clave3, valor3, NULL);

	pa2m_afirmar(hash_quitar(NULL, clave1) == NULL &&
			     hash_cantidad(hash) == 3,
		     "No se puede eliminar en un hash NULL");

	pa2m_afirmar(hash_quitar(hash, NULL) == NULL &&
			     hash_cantidad(hash) == 3,
		     "Se intenta eliminar una clave NULL y no se elimina nada");

	pa2m_afirmar(
		hash_quitar(hash, clave1) == valor1 &&
			hash_cantidad(hash) == 2 &&
			!hash_contiene(hash, clave1),
		"Se elimina clave1 con valor1 y se verifica que no contiene la clave1");

	pa2m_afirmar(
		hash_quitar(hash, clave3) == valor3 &&
			hash_cantidad(hash) == 1 &&
			!hash_contiene(hash, clave3),
		"Se elimina clave3 con valor3 y se verifica que no contiene la clave3");

	hash_destruir(hash);
}

bool continuar_iterando(const char *clave, void *valor, void *aux)
{
	if (!aux) {
		return true;
	}
	return strcmp(clave, (char *)aux) == 0;
}

void prueba_iterador()
{
	hash_t *hash = hash_crear(5);
	char *clave1 = "clave1";
	char *clave2 = "clave2";
	char *clave3 = "clave3";
	char *clave4 = "clave4";
	char *clave5 = "clave5";

	char *valor1 = "valor1";
	char *valor2 = "valor2";
	char *valor3 = "valor3";
	char *valor4 = "valor4";
	char *valor5 = "valor5";

	hash_insertar(hash, clave1, valor1, NULL);
	hash_insertar(hash, clave2, valor2, NULL);
	hash_insertar(hash, clave3, valor3, NULL);
	hash_insertar(hash, clave4, valor4, NULL);
	hash_insertar(hash, clave5, valor5, NULL);

	pa2m_afirmar(hash_con_cada_clave(NULL, continuar_iterando, NULL) == 0,
		     "No se puede iterar sobre un hash NULL");

	pa2m_afirmar(hash_con_cada_clave(hash, NULL, NULL) == 0,
		     "No se puede iterar con una funcion NULL");

	size_t iteraciones =
		hash_con_cada_clave(hash, continuar_iterando, NULL);
	pa2m_afirmar(iteraciones == hash_cantidad(hash),
		     "Se iteró sobre todas las claves del hash");

	iteraciones =
		hash_con_cada_clave(hash, continuar_iterando, (void *)clave2);
	pa2m_afirmar(
		iteraciones < hash_cantidad(hash),
		"La iteración se detiene en una clave específica antes de recorrer todo el hash");

	iteraciones =
		hash_con_cada_clave(hash, continuar_iterando, (void *)clave4);
	pa2m_afirmar(
		iteraciones == 2,
		"La iteración devuelve la cantidad correcta después de recorrer 3 claves");

	hash_destruir(hash);
}

int main()
{
	pa2m_nuevo_grupo(
		"\n======================== XXX ========================");

	pa2m_nuevo_grupo(
		"\n=============== PRUEBAS DE CREACION Y DESTRUCCION ===========");
	prueba_crear();

	pa2m_nuevo_grupo("\n=============== PRUEBAS DE INSERCION ===========");
	prueba_insertar();

	pa2m_nuevo_grupo(
		"\n=============== PRUEBAS DE ELIMINACION ===========");
	prueba_eliminar();

	pa2m_nuevo_grupo("\n=============== PRUEBAS DE ITERADOR ===========");
	prueba_iterador();

	return pa2m_mostrar_reporte();
}