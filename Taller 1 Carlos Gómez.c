#include <stdio.h>
#include <stdlib.h>

#define NUM_ESTUDIANTES 5
#define NUM_ASIGNATURAS 3
#define NOTA_APROBATORIA 6.0


int main() {

    float notas[NUM_ESTUDIANTES][NUM_ASIGNATURAS];
    float promediosEstudiantes[NUM_ESTUDIANTES];
    float promediosAsignaturas[NUM_ASIGNATURAS];
    int aprobados[NUM_ASIGNATURAS], reprobados[NUM_ASIGNATURAS];
    float maxCalif[NUM_ESTUDIANTES], minCalif[NUM_ESTUDIANTES];
    float maxcalif[NUM_ASIGNATURAS], mincalif[NUM_ASIGNATURAS];


    //inicializar contador de aprobados y reprobados
  for (int i = 0; i < NUM_ASIGNATURAS; i++){
    aprobados[i] = 0;
    reprobados[i] = 0;
  }


  //ingreso de calificaciones
  for (int i = 0; i < NUM_ESTUDIANTES; i++){
    printf("Ingrese las calificaciones del estudiante %d:\n", i+1);
    for (int j=0; j < NUM_ASIGNATURAS; j++){
      do{
        printf("Asignatura %d: ", j+1);
        scanf("%f", &notas[i][j]);
        
        if (notas[i][j] < 0 || notas[i][j] > 10){
          printf("Nota incorrecta. Ingrese una nota entre 0 y 10.\n");
        }  
      }while (notas[i][j] < 0 || notas[i][j] > 10);

      //contar aprobados y reprobados
      if (notas[i][j] >= NOTA_APROBATORIA){
        aprobados[j]++;
      } else{
        reprobados[j]++;
      }
      
    }
  }


  //calcular promedios por estudiante
  for (int i = 0; i < NUM_ESTUDIANTES; i++){
    float suma = 0;
    for (int j = 0; j < NUM_ASIGNATURAS; j++){
      suma += notas[i][j];
    }
    promediosEstudiantes[i] = suma / NUM_ASIGNATURAS;
  }


  //calculo de promedio por asignatura
for(int j=0; j < NUM_ASIGNATURAS; j++){
  float suma = 0;
  for (int i = 0; i < NUM_ESTUDIANTES; i++){
    suma += notas[i][j];
  }
  promediosAsignaturas[j] = suma / NUM_ESTUDIANTES;
}

  //calcular maxima y minima calificacion por estudiante

  for(int i = 0; i < NUM_ESTUDIANTES; i++){
    maxCalif[i] = notas[i][0];
    minCalif[i] = notas[i][0];
    for (int j = 1; j < NUM_ASIGNATURAS; j++){
      if (notas[i][j] > maxCalif[i]){
        maxCalif[i] = notas[i][j];
      } else if (notas[i][j] < minCalif[i]){
        minCalif[i] = notas[i][j];
      }  
    }
  }


  //calcular maxima y minima calificacion por asignatura
  for(int j = 0; j < NUM_ASIGNATURAS; j++){
    maxcalif[j] = notas[0][j];
    mincalif[j] = notas[0][j];
    for (int i = 1; i < NUM_ESTUDIANTES; i++){
      if (notas[i][j] > maxcalif[j]){
        maxcalif[j] = notas[i][j];
      }else if (notas[i][j] < mincalif[j]){
        mincalif[j] = notas[i][j];
      }
    }  
  }

  //Mostrar resultados
  printf("\nPromedios por estudiante:\n");
  for (int i = 0; i < NUM_ESTUDIANTES; i++){
    printf("Estudiante %d: %.2f\n", i+1, promediosEstudiantes[i]);
 }

  printf("\nPromedios por asignatura:\n");
  for (int j = 0; j < NUM_ASIGNATURAS; j++){
    printf("Asignatura %d: %.2f\n", j+1, promediosAsignaturas[j]);
  }

  printf("\nCantidad de estudiantes aprobados por asignatura:\n");
  for (int j = 0; j < NUM_ASIGNATURAS; j++){
    printf("Asignatura %d: %d\n", j+1, aprobados[j]);
  }

  printf("\nCantidad de estudiantes reprobados por asignatura:\n");
  for (int j = 0; j < NUM_ASIGNATURAS; j++){
    printf("Asignatura %d: %d\n", j+1, reprobados[j]);
  }

  printf("\nCalificaciones máximas por estudiante:\n");
  for (int i = 0; i < NUM_ESTUDIANTES; i++){
    printf("Estudiante %d: %.2f\n", i+1, maxCalif[i]);
  }

  printf("\nCalificaciones mínimas por estudiante:\n");
  for (int j = 0; j < NUM_ESTUDIANTES; j++){
    printf("Estudiante %d: %.2f\n", j+1, minCalif[j]);
  }

  printf("\nCalificaciones máximas por asignatura:\n");
  for (int j = 0; j < NUM_ASIGNATURAS; j++){
    printf("Asignatura %d: %.2f\n", j+1, maxcalif[j]);
  }

  printf("\nCalificaciones mínimas por asignatura:\n");
  for (int j = 0; j < NUM_ASIGNATURAS; j++){
    printf("Asignatura %d: %.2f\n", j+1, mincalif[j]);
  }  
    return 0;
}
