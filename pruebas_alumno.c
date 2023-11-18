#include "pa2m.h"
#include "src/hash.h"

void prueba_crear()
{
	size_t capac = 3;
	hash_t *hash = hash_crear(capac);
	pa2m_afirmar(hash != NULL, "Prueba crear un hash con capacidad 3");
	hash_destruir(hash);

	hash = hash_crear(0);
	pa2m_afirmar(
		hash != NULL,
		"Prueba crear un hash con capacidad 0 y lo crea con capacidad 3");
	hash_destruir(hash);

	hash = hash_crear(10);
	pa2m_afirmar(hash != NULL, "Prueba crear un hash con capacidad 10");
	hash_destruir(hash);

	hash = hash_crear(100);
	pa2m_afirmar(hash != NULL, "Prueba crear un hash con capacidad 100");
	hash_destruir(hash);
}

int main()
{
	pa2m_nuevo_grupo(
		"\n======================== XXX ========================");

	pa2m_nuevo_grupo(
		"\n=============== PRUEBAS DE CREACION Y DESTRUCCION ===========");
	prueba_crear();

	return pa2m_mostrar_reporte();
}