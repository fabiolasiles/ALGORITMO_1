#include "auxiliares.h"

coordenada_t obtener_coordenada_aleatoria(){

    coordenada_t coordenada;

        coordenada.fil = rand()% 20;  //VERIFICAR SI LA POSICION  ESTA INCUIDO O NO
        coordenada.col = rand()% 20; //VERIFICAR SI LA POSICION  ESTA INCUIDO O NO
    return coordenada;
}


coordenada_t obtener_coordenada_aleatoria_por_cuadrante(int cuadrante){

    coordenada_t coordenada;
    if(cuadrante == 1 ){
        coordenada.fil = rand()%9 + 1;
        coordenada.col = rand()% 19 + 1; 

    }else{// Se pasaran solo dos  cuadrantes es por eso que no se valida otra opcion
        coordenada.fil = rand()% 9 + 11;
        coordenada.col = rand()% 19 + 1; //VERIFICAR POSICIONES

    }

    return coordenada;


}



bool comparar_coordenadas(coordenada_t coordenada1, coordenada_t coordenada2){
    return (coordenada1.fil == coordenada2.fil && coordenada1.col == coordenada2.col);
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
void inicializar_obstaculos(objeto_t obstaculos[],int* tope_obstaculos,coordenada_t coordenadas[],int* tope_coordenadas){ // No se reciben las paredes porque no estan  contempladas al generar una coordenada aleatoria.
    
    int i = 0;
    

    while(i<20){
        coordenada_t coordenada_agujero;
        coordenada_agujero = obtener_coordenada_aleatoria_por_cuadrante(1);

        if(!buscar_coordenada(coordenadas,(*tope_coordenadas),coordenada_agujero)){
            objeto_t obstaculo_agujero;
            coordenadas[i] = coordenada_agujero;
            *tope_coordenadas = *tope_coordenadas + 1;
            i++;
            obstaculo_agujero.posicion = coordenada_agujero;
            obstaculo_agujero.tipo = 'A';
            obstaculos[i] = obstaculo_agujero;
            *tope_obstaculos = *tope_obstaculos +1;
        }
    }

    //Solo va un fuego
    int j = 20;
    while(j < 50){
        coordenada_t coordenada_fuego;
        coordenada_fuego = obtener_coordenada_aleatoria_por_cuadrante(obtener_cuadrante_aleatorio());
        if(!buscar_coordenada(coordenadas, *tope_coordenadas, coordenada_fuego)){
            objeto_t obstaculo_fuego;

            coordenadas[j] = coordenada_fuego;
            *tope_coordenadas  = *tope_coordenadas + 1; 

            obstaculo_fuego.posicion = coordenada_fuego;
            obstaculo_fuego.tipo = 'F';
            obstaculos[j] = obstaculo_fuego;
            *tope_obstaculos = *tope_obstaculos +1;

            j++;
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

objeto_t obtener_cuchillo(){
    objeto_t cuchillo;
    cuchillo.tipo = 'C';
    cuchillo.posicion = obtener_coordenada_aleatoria_por_cuadrante(1);
    return cuchillo;
}

objeto_t obtener_horno(){
    objeto_t horno;
    horno.tipo = 'H';
    horno.posicion = obtener_coordenada_aleatoria_por_cuadrante(2);
    return horno;
}



//otra mejor opciòn para unificar el cuchillo y horno pero buscar un nombre màs adecuado
// o paso herramientos y ya lo guardo, o no pero desde el otro lado debo agregarlos

void validar_objeto(objeto_t objeto, coordenada_t coordenadas[], int* tope_coordenadas){

    objeto = (objeto.tipo == 'C')?  obtener_cuchillo() : obtener_horno();
    int cantidad_de_objetos = 0;

    while (cantidad_de_objetos== 2){
        if(!buscar_coordenada(coordenadas, *tope_coordenadas, objeto.posicion)){
            coordenadas[*tope_coordenadas] = objeto.posicion;
            *tope_coordenadas = *tope_coordenadas +1;

            //herramientas[*tope_herramientas] = objeto;
            //*tope_herramientas = *tope_herramientas + 1;

            cantidad_de_objetos++;
        }

        objeto = objeto.tipo == 'C' ?  obtener_cuchillo() : obtener_horno();

    }

}



void inicializar_herramientas( objeto_t herramientas[],int* tope_herramientas,objeto_t obstaculos[],int tope_obtaculos,coordenada_t coordenadas[],int* tope_coordenadas){


    //Se agregan los matafuegos. ----------> Modificar porque solo irìa 1 matafuego porque solo tendremos un fuego, 
    for(int i = 20;i<tope_obtaculos;i++){
        int cuadrante_fuego = identificar_cuadrante(obstaculos[i].posicion);
        coordenada_t coordenada_extintor = obtener_coordenada_aleatoria_por_cuadrante(cuadrante_fuego);
        while(buscar_coordenada(coordenadas,*tope_coordenadas,coordenada_extintor)){
            coordenada_extintor = obtener_coordenada_aleatoria_por_cuadrante(cuadrante_fuego);

        }
        coordenadas[*tope_coordenadas] = coordenada_extintor;
        *tope_coordenadas  = *tope_coordenadas + 1;
        herramientas[*tope_herramientas].posicion= coordenada_extintor;
        *tope_herramientas = *tope_herramientas + 1;
        herramientas[*tope_herramientas].tipo = 'M';

    }
    //Se agregan los cuchillos(2) en el cuadrante de stitch.

    objeto_t cuchillo = obtener_cuchillo();
    int cantidad_de_cuchillos_buenos = 0;

    while (cantidad_de_cuchillos_buenos == 2){
        if(!buscar_coordenada(coordenadas, *tope_coordenadas, cuchillo.posicion)){
            coordenadas[*tope_coordenadas] = cuchillo.posicion;
            *tope_coordenadas = *tope_coordenadas +1;

            herramientas[*tope_herramientas] = cuchillo;
            *tope_herramientas = *tope_herramientas + 1;

            cantidad_de_cuchillos_buenos++;
        }

        cuchillo = obtener_cuchillo();

    }
    


    //Se agregan el horno(2).(suponemos en el lado del cocinero...)

    objeto_t horno = obtener_horno();
    int cantidad_de_hornos_buenos = 0;

    while (cantidad_de_hornos_buenos == 2){
        if(!buscar_coordenada(coordenadas, *tope_coordenadas, horno.posicion)){
            coordenadas[*tope_coordenadas] = horno.posicion;
            *tope_coordenadas = *tope_coordenadas +1;

            herramientas[*tope_herramientas] = horno;
            *tope_herramientas = *tope_herramientas + 1;

            cantidad_de_hornos_buenos++;
        }

        horno = obtener_cuchillo(); //podrìa reemplazarse por solo modificar la posiciòn(coordenada)

    }



    //Se agrega el puerta salida. --¡¿se debe agregar al vector de herramientas? es no verdad? porque si se respeta el orden que se agrega no deberìa y ademàs que tiene una propia "propieda" en el strcut juego

}


void inicilizar_paredes(coordenada_t paredes[], int* tope_paredes){

    *tope_paredes = 0;

    //Se lleno la fila 0 de las paredes
    for (int i=0;i<21;i++){
        coordenada_t pared;
        pared.fil = 0;
        pared.col = i;
        paredes[(*tope_paredes)+1] = pared;
        *tope_paredes = *tope_paredes + 1 ;
    }
    //Se lleno la fila 10 de las paredes
    for (int i=0;i<21;i++){
        if( i != 10){
            coordenada_t pared;
            pared.fil = 10;
            pared.col = i;
            paredes[(*tope_paredes)+1] = pared;
            *tope_paredes = *tope_paredes + 1 ;
        }
        
    }
    //Se lleno la fila 20 de las paredes
    for (int i=0;i<21;i++){
        coordenada_t pared;
        pared.fil = 20;
        pared.col = i;
        paredes[(*tope_paredes)+1] = pared;
        *tope_paredes = *tope_paredes + 1 ;
    }

    //Se lleno la columna 0 de las paredes
    for (int i=0;i<21;i++){
        coordenada_t pared;
        pared.fil = i;
        pared.col = 0;
        paredes[(*tope_paredes)+1] = pared;
        *tope_paredes = *tope_paredes + 1 ;
    }
    //Se lleno la columna 20 de las paredes
    for (int i=0;i<21;i++){
        coordenada_t pared;
        pared.fil = i;
        pared.col = 20;
        paredes[(*tope_paredes)+1] = pared;
        *tope_paredes = *tope_paredes + 1 ;
    }


}


comida_t obtener_ensalada(){
    comida_t ensalada;
    ensalada.tipo = 'E';
    ensalada.tope_ingredientes = 2;

    ensalada.ingrediente[0].esta_cocinado = false;
    ensalada.ingrediente[0].esta_cortado = false;
    ensalada.ingrediente[0].tipo = 'L';
    ensalada.ingrediente[0].posicion = obtener_coordenada_aleatoria_por_cuadrante(1);

    ensalada.ingrediente[1].esta_cocinado = false;
    ensalada.ingrediente[1].esta_cortado = false;
    ensalada.ingrediente[1].tipo = 'T';
    ensalada.ingrediente[1].posicion = obtener_coordenada_aleatoria_por_cuadrante(1);

    return ensalada;

}


comida_t obtener_ensalada_valida(coordenada_t coordenadas[], int* tope_coordenada){
    comida_t ensalada = obtener_ensalada();
//falta codear
}

coordenada_t obtener_coordenada_aleatoria_valida(coordenada_t coordenadas[], int tope_coordenada){


}

void inicializar_comidas(comida_t comidas[], int* tope_comida, coordenada_t coordenadas[], int* tope_coordenada){


}



