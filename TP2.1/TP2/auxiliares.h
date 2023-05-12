#ifndef __AUXILIARES_H__
#define __AUXILIARES_H__
#include <stdio.h>
#include <stdbool.h>
#include "cocineritos.h"
#include <stdlib.h>
#include <time.h>
#define MAX_COORDENADAS 100




int obtener_cuadrante_aleatorio();

coordenada_t obtener_coordenada_aleatoria();

coordenada_t obtener_coordenada_aleatoria_por_cuadrante(int cuadrante);

int identificar_cuadrante(coordenada_t coordenada);


bool comparar_coordenadas(coordenada_t coordenada1, coordenada_t coordenada2);

bool buscar_coordenada(coordenada_t coordenadas[MAX_COORDENADAS], int tope_coord, coordenada_t coordenada);



void inicializar_obstaculos(objeto_t obstaculos[],int* tope_obtaculos,coordenada_t coordenadas[],int* tope_coordenadas);



void inicializar_herramientas( objeto_t herramientas[],int* tope_herramientas,objeto_t obstaculos[],int tope_obtaculos,coordenada_t coordenadas[],int* tope_coordenadas);

void inicilizar_paredes(coordenada_t paredes[],int* tope_paredes);


objeto_t obtener_cuchillo();

objeto_t obtener_horno();

objeto_t obtener_salida();


void validar_objeto(objeto_t objeto, coordenada_t coordenadas[], int* tope_coordenadas);






comida_t obtener_ensalada();
comida_t obtener_pizza();
comida_t obtener_hamburguesa();
comida_t obtener_sandwich();

void inicializar_comidas(comida_t comidas[], int* tope_comida, coordenada_t coordenadas[], int* tope_coordenada);




#endif /* __COCINERITOS_H__ */