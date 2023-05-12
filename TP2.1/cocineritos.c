#include <stdio.h>
#include<stdbool.h>



coordenada_t obtener_coordenada_aleatoria(){

    coordenada_t coordenada;

        coordenada.fila = rand()% 20;  //VERIFICAR SI LA POSICION  ESTA INCUIDO O NO
        coordenada.columna = rand()% 20; //VERIFICAR SI LA POSICION  ESTA INCUIDO O NO
    return coordenada;
}


coordenada_t obtener_coordenada_aleatoria_por_cuadrante(int cuadrante){

    if(cuadrante = 1 ){
        coordenada.fila = rand()%9 + 1;
        coordenada.columna = rand()% 19 + 1; 

    }else{// Se pasaran solo dos  cuadrantes es por eso que no se valida otra opcion
        coordenada.fila = rand()% 10 + 11;
        coordenada.columna = rand()% 19 + 1; //VERIFICAR POSICIONES

    }


}



bool comparar_coordenadas(coordenada_t coordenada1, coordenada_t coordenada2){
    return (coordenada1.fila == coordenada2.fila && coordenada1.columna == coordenada2.columna);
}


bool buscar_coordenada(coordenada_t coordenadas[MAX_COORDENADAS], int tope_coord, coordenada_t coordenada){
    bool se_encontro = false;
    int pos = 0;
    while(!se_encontro && pos < tope_coord){
        if(comparar_coordenadas(coordenadas[pos], coordenada)){
            se_encontro = true;
        }
        pos++;
    }
    return se_encontro;
}


int obtener_cuadrante_aleatorio(){
    // hacer que devuelva 1 o 2
    return 1;
}
void inicializar_obstaculos(objeto_t obstaculos[],int* tope_obtaculos,coordenada_t coordenadas[],int* tope_coordenadas){ // No se reciben las paredes porque no estan  contempladas al generar una coordenada aleatoria.
    
    int i = 0;
    

    while(i<20){
        coordenada_t coordenada_agujero;
        coordenada_agujero = obtener_coordenada_aleatoria_por_cuadrante(1);

        if(!buscarCoordenada(coordenadas,(*tope_coordenadas),coordenada_agujero)){
            objeto_t obstaculo_agujero;
            coordenadas[i] = coordenada_agujero;
            (*tope_coordenadas++);
            i++;
            obstaculo_agujero.posicion = coordenada_agujero;
            obstaculo_agujero.tipo = 'A';
            obstaculos[i] = obstaculo_agujero;
            (*tope_obtaculos++);
        }
    }

    
    int j = 20;
    while(j < 50){
        coordenada_t coordenada_fuego;
        coordenada_fuego = obtener_coordenada_aleatoria_por_cuadrante(obtener_cuadrante_aleatorio());
        if(!buscarCoordenada(coordenadas, tope_coordenadas, coordenada_fuego)){
            objeto_t obstaculo_fuego;
            coordenadas[j] = coordenada_fuego;
            (*tope_coordenadas++);
            j++;
            obstaculo_agujero.posicion = coordenada_agujero;
            obstaculo_agujero.tipo = 'F';
            obstaculos[i] = obstaculo_fuego;
            (*tope_obtaculos++);
        }
    }





}


int identificar_cuadrante(coordenada_t coordenada){

    int cuadrante;
    if(coordenada.fil<10){
        cuadrante = 1;

    }else{
        cuadrante = 2;
    }
    return cuadrante;

}

void inicializar_herramientas( objeto_t herramientas[],int* tope_herramientas,objeto_t obstaculos[],int tope_obtaculos,coordenada_t coordenadas[],int* tope_coordenadas){
    //Se agregan los matafuegos.
    for(int i = 20;i<tope_obtaculos;i++){
        int cuadrante_fuego = iidentificar_cuadrante(obstaculos[i].posicion);
        coordenada_t coordenada_extintor = obtener_coordenada_aleatoria_por_cuadrante(cuadrante_fuego_);
        while(comparar_coordenadas(coordenadas,tope_coordenadas,coordenada_extintor)){
            coordenada_extintor = obtener_coordenada_aleatoria_por_cuadrante(cuadrante_fuego_);

        }
        coordenadas[*tope_coordenadas] = coordenada_extintor;
        (*tope_coordenadas++);
        herramientas[*tope_herramientas].posicion= coordenada_extintor;
        (*tope_herramientas++);
        herramientas[*tope_herramientas].tipo = 'M';

    }
    //Se agregan los cuchillos.

    //Se agregan el horno.
    //Se agrega el puerta salida.

}


void inicilizar_paredes(coordenada_t paredes[],int* tope_paredes){

    int tope_paredes = 0;

    //Se lleno la fila 0 de las paredes
    for (int i=0;i<21;i++){
        coordenada_t pared;
        pared.fil = 0;
        pared.col = i;
        paredes[(*tope_paredes)+1] = pared;
        (*tope_paredes)++;
    }
    //Se lleno la fila 10 de las paredes
    for (int i=0;i<21;i++){
        if( i != 10){
            coordenada_t pared;
            pared.fil = 10;
            pared.col = i;
            paredes[(*tope_paredes)+1] = pared;
            (*tope_paredes)++;
        }
        
    }
    //Se lleno la fila 20 de las paredes
    for (int i=0;i<21;i++){
        coordenada_t pared;
        pared.fil = 20;
        pared.col = i;
        paredes[(*tope_paredes)+1] = pared;
        (*tope_paredes)++;
    }

    //Se lleno la columna 0 de las paredes
    for (int i=0;i<21;i++){
        coordenada_t pared;
        pared.fil = i;
        pared.col = 0;
        paredes[(*tope_paredes)+1] = pared;
        (*tope_paredes)++;
    }
    //Se lleno la columna 20 de las paredes
    for (int i=0;i<21;i++){
        coordenada_t pared;
        pared.fil = i;
        pared.col = 20;
        paredes[(*tope_paredes)+1] = pared;
        (*tope_paredes)++;
    }


}



void inicializar_juego(juego_t* juego, int precio){




}




int main(){

    return 0;
}