#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ESTUDIANTES 5
#define NUM_ASIGNATURAS 3
#define NOTA_APROBATORIA 6.0
#define MAX_NOMBRE 50

int main() {

    float notas[NUM_ESTUDIANTES][NUM_ASIGNATURAS];
    float promediosEstudiantes[NUM_ESTUDIANTES];
    float promediosAsignaturas[NUM_ASIGNATURAS];
    int aprobados[NUM_ASIGNATURAS], reprobados[NUM_ASIGNATURAS];
    float maxCalif[NUM_ESTUDIANTES], minCalif[NUM_ESTUDIANTES];
    float maxcalif[NUM_ASIGNATURAS], mincalif[NUM_ASIGNATURAS];

    char nombresEstudiantes[NUM_ESTUDIANTES][MAX_NOMBRE];
    char nombresAsignaturas[NUM_ASIGNATURAS][MAX_NOMBRE];

    // Inicializar contador de aprobados y reprobados
    for (int i = 0; i < NUM_ASIGNATURAS; i++) {
        aprobados[i] = 0;
        reprobados[i] = 0;
    }

    // Ingresar nombres de las asignaturas
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        printf("Ingrese el nombre de la asignatura %d: ", j + 1);
        fgets(nombresAsignaturas[j], MAX_NOMBRE, stdin);
        nombresAsignaturas[j][strcspn(nombresAsignaturas[j], "\n")] = '\0'; // Eliminar salto de línea
    }

    // Ingresar nombres de los estudiantes y sus calificaciones
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("Ingrese el nombre del estudiante %d: \n", i + 1);  // Cambiado i++ a i+1
        fgets(nombresEstudiantes[i], MAX_NOMBRE, stdin);
        nombresEstudiantes[i][strcspn(nombresEstudiantes[i], "\n")] = '\0'; // Eliminar salto de línea

        printf("Ingrese las calificaciones de %s:\n", nombresEstudiantes[i]);
        for (int j = 0; j < NUM_ASIGNATURAS; j++) {
            do {
                printf("%s: ", nombresAsignaturas[j]);
                scanf("%f", &notas[i][j]);

                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("Nota incorrecta. Ingrese una nota entre 0 y 10.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);

            // Contar aprobados y reprobados
            if (notas[i][j] >= NOTA_APROBATORIA) {
                aprobados[j]++;
            } else {
                reprobados[j]++;
            }
        }
        getchar();  // Para consumir el salto de línea residual después de scanf
    }

    // Calcular promedios por estudiante
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        float suma = 0;
        for (int j = 0; j < NUM_ASIGNATURAS; j++) {
            suma += notas[i][j];
        }
        promediosEstudiantes[i] = suma / NUM_ASIGNATURAS;
    }

    // Calcular promedios por asignatura
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        float suma = 0;
        for (int i = 0; i < NUM_ESTUDIANTES; i++) {
            suma += notas[i][j];
        }
        promediosAsignaturas[j] = suma / NUM_ESTUDIANTES;
    }

    // Calcular máxima y mínima calificación por estudiante
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        maxCalif[i] = notas[i][0];
        minCalif[i] = notas[i][0];
        for (int j = 1; j < NUM_ASIGNATURAS; j++) {
            if (notas[i][j] > maxCalif[i]) {
                maxCalif[i] = notas[i][j];
            } else if (notas[i][j] < minCalif[i]) {
                minCalif[i] = notas[i][j];
            }
        }
    }

    // Calcular máxima y mínima calificación por asignatura
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        maxcalif[j] = notas[0][j];
        mincalif[j] = notas[0][j];
        for (int i = 1; i < NUM_ESTUDIANTES; i++) {
            if (notas[i][j] > maxcalif[j]) {
                maxcalif[j] = notas[i][j];
            } else if (notas[i][j] < mincalif[j]) {
                mincalif[j] = notas[i][j];
            }
        }
    }

    // Mostrar resultados
    printf("\nPromedios por estudiante:\n");
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("%s: %.2f\n", nombresEstudiantes[i], promediosEstudiantes[i]);
    }

    printf("\nPromedios por asignatura:\n");
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        printf("%s: %.2f\n", nombresAsignaturas[j], promediosAsignaturas[j]);
    }

    printf("\nCantidad de estudiantes aprobados por asignatura:\n");
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        printf("%s: %d\n", nombresAsignaturas[j], aprobados[j]);
    }

    printf("\nCantidad de estudiantes reprobados por asignatura:\n");
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        printf("%s: %d\n", nombresAsignaturas[j], reprobados[j]);
    }

    printf("\nCalificaciones maximas por estudiante:\n");
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("%s: %.2f\n", nombresEstudiantes[i], maxCalif[i]);
    }

    printf("\nCalificaciones minimas por estudiante:\n");
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("%s: %.2f\n", nombresEstudiantes[i], minCalif[i]);
    }

    printf("\nCalificaciones maximas por asignatura:\n");
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        printf("%s: %.2f\n", nombresAsignaturas[j], maxcalif[j]);
    }

    printf("\nCalificaciones minimas por asignatura:\n");
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        printf("%s: %.2f\n", nombresAsignaturas[j], mincalif[j]);
    }

    return 0;
}
