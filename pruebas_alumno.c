#include "pa2m.h"
#include "src/hash.h"

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
	// char *clave2 = "clave2";
	// char *clave3 = "clave3";
	// char *clave4 = "clave4";
	// char *clave5 = "clave5";
	// char *clave6 = "clave6";
	// char *clave7 = "clave7";

	char *valor1 = "valor1";
	// char *valor2 = "valor2";
	// char *valor3 = "valor3";
	// char *valor4 = "valor4";
	// char *valor5 = "valor5";
	// char *valor6 = "valor6";
	// char *valor7 = "valor7";

	pa2m_afirmar(hash_insertar(hash, clave1, valor1, NULL) == hash &&
			     hash_cantidad(hash) == 1,
		     "Se inserta clave1 con valor1");
	hash_destruir(hash);
}

int main()
{
	pa2m_nuevo_grupo(
		"\n======================== XXX ========================");

	pa2m_nuevo_grupo(
		"\n=============== PRUEBAS DE CREACION Y DESTRUCCION ===========");
	prueba_crear();

	pa2m_nuevo_grupo("\n=============== PRUEBAS DE INSERTAR ===========");

	return pa2m_mostrar_reporte();
}