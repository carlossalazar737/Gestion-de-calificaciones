/*
Autor:Carlos Salazar
Fecha de entrega: 31/05/2026
Descripción: Codigo en C que permite a una escuela ingresar las notas de los estudiantes que requieran para tres asignaturas en especifico y con un amplio conocimiento de promedios, notas mas altas y bajas, entre otras.
*/

#include <stdio.h>
int main(int crgc, char *argv[]){
    int estudiantes;
    int i, j;
    float suma;
    printf("Ingrese el numero de estudiantes: ");
    while (scanf("%d", &estudiantes) != 1 || estudiantes <= 0) {
        printf("Entrada invalida. Por favor, ingrese un numero entero positivo: ");
        while (getchar() != '\n');
    }
    float notas[estudiantes][5];
    for (i = 0; i < estudiantes; i++) {
        printf("\nEstudiante %d\n", i + 1);

        for (j = 0; j < 3; j++){
            do {
                printf("Ingrese la nota de la asignatura %d: ", j + 1);
                if (scanf("%f", &notas[i][j]) != 1){
                    printf("Entrada invalida. Ingrese un numero.\n");
                    while (getchar() != '\n');
                    notas[i][j] = -1;
                }
                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("La nota debe estar entre 0 y 10.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }
printf("\n========== PROMEDIO POR ESTUDIANTE ==========\n");
    for (i = 0; i < estudiantes; i++) {
        suma = 0;
        for (j = 0; j < 3; j++) {
            suma += notas[i][j];
        }
        printf("Estudiante %d: %.2f\n", i + 1, suma / 3);
    }
printf("\n========== PROMEDIO POR ASIGNATURA ==========\n"); 
    for (j = 0; j < 3; j++) {
        suma = 0;
        for (i = 0; i < estudiantes; i++){
            suma += notas[i][j];
        }
        printf("Asignatura %d: %.2f\n", j + 1, suma / estudiantes);
    }
printf("\n========== MAYOR Y MENOR POR ESTUDIANTE ==========\n");
    for (i = 0; i < estudiantes; i++) {
        float mayor = notas[i][0];
        float menor = notas[i][0];

        for (j = 1; j < 3; j++) {
            if (notas[i][j] > mayor) {
                mayor = notas[i][j];
            }

            if (notas[i][j] < menor) {
                menor = notas[i][j];
            }
        }
        printf("Estudiante %d -> Mayor: %.2f | Menor: %.2f\n",
               i + 1, mayor, menor);
    }
printf("\n========== DATOS POR ASIGNATURA ==========\n");
    for (j = 0; j < 3; j++) {
        float mayor = notas[0][j];
        float menor = notas[0][j];

        int aprobados = 0;
        int reprobados = 0;

        for (i = 0; i < estudiantes; i++) {
            if (notas[i][j] > mayor) {
                mayor = notas[i][j];
            }
            if (notas[i][j] < menor) {
                menor = notas[i][j];
            }
            if (notas[i][j] >= 6) {
                aprobados++;
            }
            else {
                reprobados++;
            }
        }
        printf("\nAsignatura %d\n", j + 1);
        printf("Nota mayor: %.2f\n", mayor);
        printf("Nota menor: %.2f\n", menor);
        printf("Aprobados: %d\n", aprobados);
        printf("Reprobados: %d\n", reprobados);
    }
    return 0;
}