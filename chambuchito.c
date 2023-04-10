#include <stdio.h>
#include<stdbool.h>

#define MEDIDA_MINIMA 15
#define MEDIDA_MAXIMA 30

#define PAN_BLANCO 'B'
#define PAN_INTEGRAL 'I'
#define PAN_AVENA_Y_MIEL 'A'
#define PAN_QUESO_Y_OREGANO 'Q'

#define DAMBO 'D'
#define CHEDDAR 'C'
#define GRUYERE 'G'
#define SIN_QUESO 'S'

#define ROAST_BEEF 'R'
#define ATUN 'A'
#define SOJA 'S'
#define POLLITO 'P'
#define NADA_DE_PROTE 'N'

#define AFIRMATIVO 'S'
#define NEGATIVO 'N'

#define PRECIO_PAN_BASICO 5
#define PRECIO_PAN_ESPECIAL 8

#define PRECIO_QUESO_BASICO 5
#define PRECIO_QUESO_ESPECIAL 8
#define PRECIO_SIN_QUESO 0

#define PRECIO_ROAST_BEEF 7
#define PRECIO_ATUN 9
#define PRECIO_POLLITO 5 
#define PRECIO_SOJA 3
#define PRECIO_NADA_DE_PROTE 0

#define ERROR -1

const float VALOR_VENTA = 0.3f;




/*
 * PRE:-
 * POST: La funcion devuelve "true" si la respuesta de la pregunta es una de las presentadas.
 */

bool validarCalentarProducto(char opcionQuintaPregunta){
    return(opcionQuintaPregunta==AFIRMATIVO || opcionQuintaPregunta==NEGATIVO);

}

/*
 * PRE: Se mostrara al usuario siempre y cuando la respuesta de la cuarta pregunta no sea "ATUN".
 * POST: Realiza la quinta pregunta al usuario, hasta que la respuesta sea una de las opciones presentadas.
 */

void preguntaCalentarSandwich(char* opcionQuintaPregunta){
    while(!validarCalentarProducto(*opcionQuintaPregunta)){
        printf("¿Deseas tu chambuchito caliente?[S/N]\n");
        scanf(" %c\n",opcionQuintaPregunta);
    }
       
}

/*
 * PRE: Dede ingresarse una respuesta valida a las opciones a evaluar.
 * POST: Devuelve el costo dependiendo el tipo de proteina  que eligio el usuario.
 */

int evaluarCostoProteina(char* cuartaRespuesta,int* costoProteina){
    
    if (*cuartaRespuesta== ROAST_BEEF){
        (*costoProteina) = PRECIO_ROAST_BEEF;

    }else if(*cuartaRespuesta == ATUN){
        (*costoProteina) = PRECIO_ATUN;

    }else if (*cuartaRespuesta == POLLITO){
        (*costoProteina) = PRECIO_POLLITO;

    }else if (*cuartaRespuesta == SOJA){
        (*costoProteina) = PRECIO_SOJA;

    }else if (*cuartaRespuesta == NADA_DE_PROTE){
        (*costoProteina) = PRECIO_NADA_DE_PROTE;
        
    }else{
        (*costoProteina) = ERROR;

    }
    return (*costoProteina);
}


/*
 * PRE:-
 * POST: Funcion que determina si la opcion dada es alguna de las indicadas.
 */

bool validarOpcionProteinaElegida(char opcion){
    return(opcion==ROAST_BEEF|| opcion==ATUN || opcion==SOJA || opcion==POLLITO || opcion==NADA_DE_PROTE);
}


/*
 * PRE:-
 * POST: Realiza la cuarta pregunta al usuario, hasta que la respuesta sea una de las opciones presentadas.
 */

char preguntaProteinaSandwich(char* opcionCuartaPregunta){
    while(!validarOpcionProteinaElegida(*opcionCuartaPregunta)){
        printf("¿Que proteina queres en su chambuchito?\n");
        printf("Por favor, ingrese una de estas opciones:\n");
        printf("- Roast Beef [R] \n");
        printf("- Atun [A] \n");
        printf("- Soja [S] \n");
        printf("- Pollito [P] \n");
        printf("- Nada de Prote [N] \n");
        scanf(" %c",opcionCuartaPregunta);
    }
    return(*opcionCuartaPregunta);
}

/*
 * PRE: Dede ingresarse una respuesta valida a las opciones a evaluar.
 * POST: Devuelve el costo dependiendo el tipo de queso  que eligio el usuario.
 */

int evaluarCostoQueso(char* tercerRespuesta,int* costoQueso){
    
    if (*tercerRespuesta== DAMBO || *tercerRespuesta == CHEDDAR){
        (*costoQueso) = PRECIO_QUESO_BASICO;

    }else if(*tercerRespuesta==GRUYERE){
        (*costoQueso) = PRECIO_QUESO_ESPECIAL;

    }else if (*tercerRespuesta==SIN_QUESO){
        (*costoQueso) = PRECIO_SIN_QUESO;
    }else{
        (*costoQueso) = ERROR;
    }
    return (*costoQueso);
}

/*
 * PRE:-
 * POST: Funcion que determina si la opcion dada es alguna de las indicadas.
 */

bool validarOpcionQuesoElegida(char opcion){
    return(opcion==DAMBO|| opcion==CHEDDAR || opcion==GRUYERE || opcion==SIN_QUESO);
}


/*
 * PRE:-
 * POST: Realiza la tercer pregunta al usuario, hasta que la respuesta sea una de las opciones presentadas.
 */

char preguntaQuesoSandwich(char* opcionTercerPregunta){
    while(!validarOpcionQuesoElegida(*opcionTercerPregunta)){
        printf("¿Que queso queres en su chambuchito?\n");
        printf("Por favor, ingrese una de estas opciones:\n");
        printf("- Dambo [D] \n");
        printf("- Cheddar [C] \n");
        printf("- Gruyere [G] \n");
        printf("- Sin Queso [S] \n");
        scanf(" %c",opcionTercerPregunta);
    }
    return(*opcionTercerPregunta);
}

/*
 * PRE: Dede ingresarse una respuesta valida a las opciones a evaluar.
 * POST: Devuelve el costo dependiendo el tipo de pan que eligio el usuario.
 */

int evaluarCostoPan(char* segundaRespuesta,int* costoPan){
    
    if (*segundaRespuesta==PAN_BLANCO || *segundaRespuesta ==PAN_INTEGRAL){
        (*costoPan) = PRECIO_PAN_BASICO;

    }else if(*segundaRespuesta==PAN_AVENA_Y_MIEL || *segundaRespuesta ==PAN_QUESO_Y_OREGANO){
        (*costoPan) = PRECIO_PAN_ESPECIAL;

    }else{
        (*costoPan) = ERROR;
    }
    return (*costoPan);
}


/*
 * PRE:-
 * POST: Funcion que determina si la opcion dada es alguna de las indicadas.
 */

bool validarOpcionElegida(char opcion){
    return(opcion==PAN_BLANCO|| opcion==PAN_INTEGRAL || opcion==PAN_AVENA_Y_MIEL || opcion==PAN_QUESO_Y_OREGANO);
}


/*
 * PRE:-
 * POST: Realiza la segunda pregunta al usuario, hasta que la respuesta sea una de las opciones presentadas.
 */

char preguntaPanSandwich(char* opcionSegundaPregunta){
    while(!validarOpcionElegida(*opcionSegundaPregunta)){
        printf("¿Que pan desea en su chambuchito?\n");
        printf("Por favor, ingrese una de estas opciones:\n");
        printf("- Blanco [B] \n");
        printf("- Integral [I] \n");
        printf("- Avena y Miel [A] \n");
        printf("- Queso y Oregano [Q] \n");
        scanf(" %c",opcionSegundaPregunta);
    }
    return(*opcionSegundaPregunta);
}


/*
 * PRE:-
 * POST: La funcion devuelve "true" si el numero ingresado esta entre el rango de MEDIDA_MINIMA y MEDIDA_MAXIMA, en caso contrario devuelve "false".
 */

bool validarRangoMedida( int opcionPrimeraPregunta){
    return(opcionPrimeraPregunta>=MEDIDA_MINIMA && opcionPrimeraPregunta<=MEDIDA_MAXIMA);

}

/*
 * PRE:-
 * POST: Realiza la primera pregunta al usuario, hasta que la respuesta sea una de las opciones presentadas.
 */
 
int preguntaMedidaSandwich( int* opcionPrimeraPregunta){
    while(!validarRangoMedida(*opcionPrimeraPregunta)){
        printf("¿De que  medida desea su chambuchito?\n");
        printf("Debe ingresar un numero entre 15 y 30 inclusive\n");
        scanf(" %i",opcionPrimeraPregunta);
    }
    return (*opcionPrimeraPregunta);
}

/*
 * PRE:-
 * POST: La funcion devuelve "true" si el numero ingresado esta entre el rango de MEDIDA_MINIMA y MEDIDA_MAXIMA, en caso contrario devuelve "false".
 */
//int calculartPrecioSandwich(){


//}





 int main(){
    int opcionPrimeraPregunta = 12;
    char opcionSegundaPregunta = 'x';
    char opcionTercerPregunta = 'X';
    char opcionCuartaPregunta = 'X';
    char opcionQuintaPregunta = 'X';

    int primerRespuesta;
    char segundaRespuesta;
    char tercerRespuesta;
    char cuartaRespuesta;

    int costoPan =0;
    int costoQueso = 0;
    int costoProteina = 0;
    int precioTotal = 0;

    primerRespuesta = preguntaMedidaSandwich(&opcionPrimeraPregunta);
    printf(" %i\n",primerRespuesta);

    segundaRespuesta = preguntaPanSandwich(&opcionSegundaPregunta);
    costoPan = evaluarCostoPan(&segundaRespuesta,&costoPan);
    printf(" %i\n",costoPan);

    tercerRespuesta = preguntaQuesoSandwich(&opcionTercerPregunta);
    costoQueso = evaluarCostoQueso(&tercerRespuesta,&costoQueso);
    printf(" %i\n",costoQueso);

    cuartaRespuesta = preguntaProteinaSandwich(&opcionCuartaPregunta);
    costoProteina = evaluarCostoProteina(&cuartaRespuesta,&costoProteina);
    printf(" %i\n",costoProteina);

    
    

    if (cuartaRespuesta == ATUN){
        float totalIngredientes = (float)(costoProteina + costoPan + costoQueso);
        float primerTotal= VALOR_VENTA * (float)primerRespuesta;
        precioTotal = (int)(totalIngredientes*primerTotal);
        printf("%i\n",precioTotal);

    }else{

        preguntaCalentarSandwich(&opcionQuintaPregunta);
        float totalIngredientes = (float)(costoProteina + costoPan + costoQueso);
        float primerTotal= VALOR_VENTA * (float)primerRespuesta;
        precioTotal = (int)(totalIngredientes*primerTotal);
        printf("%i\n",precioTotal);
    }
    
 }