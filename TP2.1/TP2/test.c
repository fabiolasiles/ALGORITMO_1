#include <stdio.h>
#include <stdbool.h>
#include "auxiliares.h"



void mostrar_40_coordenadas_aleatorias_en_el_primer_cuadrante(){
    coordenada_t coordenada;
    for(int i = 0; i < 40; i++){
        coordenada = obtener_coordenada_aleatoria_por_cuadrante(1);
        printf("(%i,%i) \n", coordenada.fil, coordenada.col);
    }
}

void mostrar_40_coordenadas_aleatorias_en_el_segundo_cuadrante(){
    coordenada_t coordenada;
    for(int i = 0; i < 40; i++){
        coordenada = obtener_coordenada_aleatoria_por_cuadrante(2);
        printf("(%i,%i) \n", coordenada.fil, coordenada.col);
    }
}

int main(){
    mostrar_40_coordenadas_aleatorias_en_el_primer_cuadrante(); //Verificar que estè la fila entre 1-9(incluidos) y la columna entre 1 -19(incluìdos) OK

    printf("-------------------------------------------------------------------------\n");
    
    mostrar_40_coordenadas_aleatorias_en_el_segundo_cuadrante();


    return 0;
}