#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    punto5();
    return 0;
}

int punto5 () {

    /* DECLARACION DE VARIABLES */
    char *str = malloc(300); char *end;
    int esPalindromo = 1, i = 0, middle, control = 1;

    /* PIDE AL USUARIO QUE INGRESE UNA CADENA Y LA LEE */
    printf("Ingrese una cadena: ");
    scanf("%s", str);
    printf("\n");

    /* CALCULA LA MITAD Y SETEA UN PUNTERO AL FINAL */
    end = (str + strlen(str) - 1);
    middle = strlen(str)/2;

    /* MIENTRAS NO HAYA LLEGADO A LA MITAD Y SIGA SIENDO PALINDROMO,
        CONTROLA LA PRIMER LETRA CON LA ULTIMA */
    while ( control && esPalindromo ) {
        printf(" str : %c --- end: %c\n", *str, *end);
        esPalindromo = (*str == *end);
        str++; end--;
        i++;
        control = (i < middle);
    }


    printf("Es palindromo: %d", esPalindromo);

    return 0;

}
