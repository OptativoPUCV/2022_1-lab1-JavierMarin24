#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//#include "exercises.h"

/* 
Ejercicio 1.
Función que recibe 3 parámetros (a, b y c), 
y en c almacena el valor de la suma de a más b.
*/

void suma(int a, int b, int * c) {
   *c= a+b;
}
    

/*
Esta función suma los N primeros números del arreglo a
*/
int sumaN(int a[], int N) {
    int i;
    int tot = 0;

    for(i = 0; i < N; i++) {
      tot += a[i];
    }

    return tot;
}

/*
Ejercicio 2.
Esta función debe sumar los últimos m números del 
arreglo a y almacena el resultado en *suma.
Utilice la función sumaN.
*/

void sumaNultimos(int a[], int n, int m, int * suma) {
 int i;
 *suma=0;
 for (i=0; i<n ; i++)
 {
    *suma += *(a+i);
 }
 *suma -= sumaN( a, n-m);
}

/*
Ejercicio 3.
Considerando la estructura Persona, programe la función
crearPersona(...), la cual crea una nueva persona con 
los datos correspondientes y retorna un puntero al dato 
recién creado.
*/
typedef struct {
  char nombre[30];
  char rut[11];
  int edad;
} Persona;


Persona* crearPersona(char nombre[], char rut[], int edad) {
   Persona *perfil;
    perfil = (Persona*) malloc (sizeof(Persona));
   strcpy( perfil->nombre,  nombre);
   strcpy( perfil->rut,  rut);
   perfil->edad=edad;
   return perfil;
}

/*
Ejercicio 4.
Considerando la estructura "Vector", escriba 
la función Vector* crearVector(int n), la cual crea 
un vector con capacidad `n`, reserva la memoria 
correspondiente para el arreglo con `n` datos 
inicializados en 0 y luego retorna el vector creado.
*/
typedef struct {
   int * datos; // arreglo dinámico
   int capacidad; // capacidad del arreglo
} Vector;

Vector * crearVector(int n) {
   //frases = (tipoLetra *) realloc (frases, n+1 * sizeof(tipoLetra));
   Vector *arreglo = NULL;
   arreglo = (Vector *) malloc  (sizeof(Vector));
   arreglo->datos = (int * ) calloc (n,(sizeof(int)));
   arreglo->capacidad=n;
   return arreglo;
}

/*
Ejercicio 5a.
Programe la función void asignarValor(Vector * v, int i, int valor), 
la cual asigna el valor a la posición i del vector v.
*/
void asignarValor(Vector * v, int i, int valor) {
  v->datos[i]=valor;
}

/*
Ejercicio 6.
Programe la función int obtenerValor(Vector * v, int i), 
la cual retorna el valor en la posición i del vector v.
*/
int obtenerValor(Vector * v, int i) {
   return v->datos[i];
}

/*
Ejercicio 7.
Función que suma los vectores `a` y `b` y 
actualiza el vector `c` con el resultado de la suma.
*/
void sumaV(Vector * a, Vector * b, Vector * c) {
int sumando;

for(int i=0; i< a->capacidad ; i++)
{
   sumando=0;
   sumando = a->datos[i]+b->datos[i];
   c->datos[i]=sumando;
}
}

/*
Ejercicio 8.
Use las operaciones implementadas de vectores para 
sumar (a1,a2)+(b1+b2). Almacene el resultado en el vector c.
*/
void sumaV2(int a1, int a2, int b1, int b2, Vector *c){
   Vector arregloA;
    arregloA=*crearVector(2);
   Vector arregloB;
  arregloB=*crearVector(2);
   asignarValor(  &arregloA,  0,  a1);
   asignarValor(  &arregloA,  1,  a2);
   asignarValor(  &arregloB,  0,  b1);
   asignarValor(  &arregloB,  1,  b2);
   sumaV( &arregloA,   &arregloB,  c);
}
