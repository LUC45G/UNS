#include <stdio.h>
#include <stdlib.h>

char fichas [9];
int turno = 0;

void InicializarFichas() {
    for(int i = 0; i < 9; i++) {
        fichas[i] = ' ';
    }
}

void ImprimirTablero() {
    printf(" %c | %c | %c \n", fichas[0], fichas[1], fichas[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", fichas[3], fichas[4], fichas[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", fichas[6], fichas[7], fichas[8]);
}

int ColocarFicha(int x, int y, int jugador) {

    system("cls");

    if ( ( fichas[( 3*(y-1) )+ x-1 ] != ' ') || ( ((3*(y-1))+ x-1) > 9 ) ) {
        ImprimirTablero();
        return 1;
    }

    fichas[( 3*(y-1) )+ x-1 ] = (jugador == 1) ? 'X' : 'O';
    turno++;
    ImprimirTablero();
    return 0;

}



int main() {
    int x, y, control; // Variables de posicion y control

    InicializarFichas(); // Inicializa el arreglo de caracteres con ' '
    ImprimirTablero(); // Imprime el tablero inicialmente vacio

    while ( turno < 9 ) {
        // La variable de control 'turno' se incrementa en las llamadas a ColocarFicha

        if(turno%2) { // Si turno % 2 == 1 significa que es turno del jugador 2
            do {
                printf("TURNO: %i \nJugador dos, ingrese coordenadas\n", turno);
                printf("x: "); scanf("%i", &x);
                printf("y: "); scanf("%i", &y);
                control = ColocarFicha(x, y, 2);
            } while ( control );
        } else {
            do {
                printf("TURNO: %i \nJugador uno, ingrese coordenadas\n", turno);
                printf("x: "); scanf("%i", &x);
                printf("y: "); scanf("%i", &y);
                control = ColocarFicha(x, y, 1);
            } while ( control ); // Pide coordenadas al jugador y cicla hasta que las coordenadas sean validas
        }
    }


    return 0;
}
