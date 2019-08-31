#include <stdio.h>
#include <stdlib.h>
int potencia(int a, int b);
int convertirADecimal(char c);
int contarDigitos(int n);

int main() {
    punto14();
    return 0;
}

int punto1() {
    int sumaPares = 0; int cantPares = 0;
    int multipImpares = 1; int cantImpares = 0;
    int i = 1;

    while(cantImpares < 10 || cantPares < 10) {

        if ( cantImpares < 10 && i%2 ) {
            multipImpares *= i;
            cantImpares++;
        }
        else if( cantPares < 10){
            sumaPares += i;
            cantPares++;
        }

        i++;

    }

    printf("Producto de los 10 primeros impares: %d. \nSuma de los 10 primeros pares: %d. \nValor de i: %d.", multipImpares, sumaPares, i);



    return 0;
}

int punto2() {
    printf("Ingrese un numero natural: ");
    int max;
    scanf("%d", &max);
    printf("\n");

    int suma = 0;

    for (int i = 0; i < max; i++)
        suma += i;

    printf("La suma de los %d primeros numeros naturales es: %d", max, suma);

    return 0;
}

int punto4() {
    int option;
    float value;

    printf("Seleccione operacion: \n1) Convertir Celsius a Fahrenheit.\n2) Convertir yardas a metros.\n3) Convertir millas por hora a kilometros por hora.\n4) Convertir litros cada 100km a millas por galon.\n");
    scanf("%d", &option);
    printf("\nIngrese el valor a convertir: ");
    scanf("%f", &value);

    switch ( option ) {
        case 1:
            printf("%3f Celsius es equivalente a %f Fahrenheit.", value, (value * 1.8) + 32 );
            break;
        case 2:
            printf("%f yardas es equivalente a %f metros.", value, (value / 1.094) );
            break;
        case 3:
            printf("%f millas por hora es equivalente a %f kilometros por hora.", value, (value * 1.609) );
            break;
        case 4:
            printf("%f litros cada 100km es equivalente a %f millas por galon.", value, (235.210 / value) );
            break;
        default:
            printf("%d No es una operacion valida.", option );
            break;
    }

    return 0;
}

int punto5() {
    int option;
    float valueA; float valueB;
    float resultado;

    printf("Seleccione operacion: \n1 -> + \n2 -> - \n3 -> * \n4 -> / \n");
    scanf("%d", &option);

    printf("\nIngrese dos numeros reales: \n");
    scanf("%f", &valueA); scanf("%f", &valueB);

    resultado = ( (option == 1) * (valueA + valueB) ) + ( (option == 2) * (valueA - valueB) ) + ( (option == 3) * (valueA * valueB) ) + ( (option == 4) * (valueA / valueB) );

    printf("\nResultado de la operacion: %f", resultado);

}

int punto6() {

    int value;

    printf("Ingrese un numero natural: ");
    scanf("%d", &value);

    for (int i = 1; i < 21; i++) {
        printf("%d * %d = %d \n", value, i, value*i);
    }

    return 0;
}

int punto7() {
    int cantidad;
    char caux;
    long mayor = -100000, menor = 100000, promedio, suma = 0;

    printf("Ingrese la longitud de la serie: ");
    scanf("%d", &cantidad);
    scanf("%c", &caux);

    long serie [cantidad];

    for (int i = 0; i < cantidad; i++) {
        long aux;
        printf("Elemento %d: ", i);
        scanf("%ld", &aux);
        scanf("%c", &caux);
        serie[i] = aux;
    }

    for(int i = 0; i < cantidad; i++) {
        menor = ( serie[i] < menor ) ? serie[i] : menor;
        mayor = ( serie[i] > mayor ) ? serie[i] : mayor;
        suma += serie[i];
    }

    promedio = suma / cantidad;

    printf("El mayor numero de la serie es: %ld. \nEl menor numero de la serie es: %ld. \nEl promedio de la serie es %ld.", mayor, menor, promedio);

    return 0;
}

int punto8() {
    int inputValue, outputValue = 0, i = 0, aux;

    printf("Ingrese un numero en notacion binaria: \n");
    scanf("%d", &inputValue);

    while ( inputValue > 0 ) {

        aux = inputValue % 10;
        outputValue += ( aux * potencia(2, i) );

        i++;
        inputValue /= 10;
    }

    printf("Su equivalente decimal es %d", outputValue);

    return 0;
}

int potencia(int a, int b) {
    int aux = 1;

    for ( int i = 0; i < b; i++)
        aux *= a;

    return aux;
}

int punto9() {

    // TODO: Verificar que la cadena sea exclusivamente hexadecimal;
    char input[10], aux[100];

    for( int j = 0; j < 10; j++ ) {
        input[j] = 'X';
    }

    int output = 0, condition = 1, auxCondition = 1, i = 0, length = 0;

    char caux;


    printf("Ingrese una cadena de digitos hexadecimales: \n");
    scanf("%s", input);

    for( int k = 0; auxCondition || k < 10; k++ ) {
        length++;
        auxCondition =  input[k] != '\0' || input[k] == '\n';
    }

    printf(" length: %d\n", length);

    while(condition) {
        caux = input[i];

        if( input[i] != ' ' )
            output += ( convertirADecimal(caux) * potencia( 16, length));

        i++;
        length--;
        condition = input[i] != '\0' || input[i] == '\n';
    }

    printf("El valor en decimal es: %d", output);


    return 0;
}

int convertirADecimal(char c) {
    int r;

    switch(c) {
        case 'A':
            r = 10;
            break;
        case 'B':
            r = 11;
            break;
        case 'C':
            r = 12;
            break;
        case 'D':
            r = 13;
            break;
        case 'E':
            r = 14;
            break;
        case 'F':
            r = 15;
            break;
        default:
            r = (int)  c;
            r = r - 48;
            break;
    }

    return r;
}

int punto10() {

    int input, digits = 0;

    printf("Ingrese un numero entero: \n");
    scanf("%i", &input);

    printf("\nDigito ingresado: %d - Ubicacion en memoria: %d", input, &input);
    digits = contarDigitos(input);

    printf("\nCantidad de digitos: %i", digits);

    return 0;
}

int contarDigitos(int n) {
    if ( n == 0 ) {
            printf("\n%i", n);
        return 0;
    }
    else {
        printf("\n%i", n);
        return contarDigitos(n/10) + 1;
    }
}

int punto11() {
    int input;

    printf("Ingrese un numero entero: ");
    scanf("%d", &input);
    printf("\n");

    if ( esProlijoAsc(input) || esProlijoDesc(input) ) {
        printf("Es un numero prolijo :D");
    }
    else {
        printf("No es un numero prolijo >:(");
    }
}

int esProlijoAsc(int n) {

    if ( n%10 == 0 ) {
        return 1;
    }
    else {
        return ( (n%10) > ( (n/10)%10 ) ) && esProlijoAsc(n/10);
    }
}

int esProlijoDesc(int n) {

    if ( n/10 == 0 ) {
        return 1;
    }
    else {
        return ( (n%10) < ( (n/10)%10 ) ) && esProlijoDesc(n/10);
    }
}

int punto14() {
    int input;

    printf("Ingrese un numero entero: ");
    scanf("%d", &input);
    printf("\n");


    printf("El cuadrado de %d es %d", input, cuadrado(input));
}

int cuadrado(int i) {

    if ( i == 1 ) {
        return 1;
    }
    else {
        return cuadrado(i-1) + ( (2*i) - 1);
    }

}


