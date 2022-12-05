// Universidad de Colima
// Facultad de Ingeniería Electromecánica
// Ingeniería de Software 3er Semestre
// Materia: Estructura de Datos
// Alumna: Ximena Manzo Castrejón 
// Fecha: Diciembre 05, 2022

#include<stdio.h>
#include<stdlib.h>

struct nodo{ //Declaración de estructura
  struct nodo* hijo_izq;
  struct nodo* hijo_der;
  int dato;
};

struct nodo* nuevoNodo(int dato){ //Uso de la estructura
  size_t tam_nodo = sizeof(struct nodo);
  struct nodo* nuevo_nodo = (struct nodo*) malloc(tam_nodo); //memory allocation
  nuevo_nodo->dato=dato;
  nuevo_nodo->hijo_izq = NULL;
  nuevo_nodo->hijo_der = NULL;
  return nuevo_nodo;
}

void insertarNodo(struct nodo* nd, int dato){
  if(dato > nd->dato){
    if(nd->hijo_der == NULL){
      nd->hijo_der = nuevoNodo(dato);
    }else{
      insertarNodo(nd->hijo_der, dato);
    }
  }else{
    if(nd->hijo_izq == NULL){
      nd->hijo_izq = nuevoNodo(dato);
    }else{
      insertarNodo(nd->hijo_izq, dato);
    }
  }
}

int rastreo(struct nodo* nd, int dato, int nivel){
  if(nd == NULL)
	  return 0;
  if(nd->dato == dato)
	  return nivel;
  int nuevo_nivel = rastreo(nd->hijo_izq, dato, nivel + 1);
  if(nuevo_nivel!=0)
	  return nuevo_nivel;
  nuevo_nivel = rastreo(nd->hijo_der, dato, nivel + 1);
}

int buscar(struct nodo* nd, int dato){
  return rastreo(nd, dato, 1);
}

void preorden(struct nodo* raiz){
  if(raiz!=NULL){
    printf("%d, ", raiz->dato);
    preorden(raiz->hijo_izq);
    preorden(raiz->hijo_der);
  }
}

void inorden(struct nodo* raiz){
  if(raiz!=NULL){
    inorden(raiz->hijo_izq);
    printf("%d, ", raiz->dato);
    inorden(raiz->hijo_der);
  }
}
void postorden(struct nodo* raiz){
  if(raiz!=NULL){
    postorden(raiz->hijo_izq);
    postorden(raiz->hijo_der);
    printf("%d, ", raiz->dato);
  }
}

int main(){
  struct nodo* raiz = NULL;
  raiz = nuevoNodo(28);
  insertarNodo(raiz, 11);
  insertarNodo(raiz, 96);
  insertarNodo(raiz, 21);
  insertarNodo(raiz, 6);
  insertarNodo(raiz, 97);
  insertarNodo(raiz, 1);
  insertarNodo(raiz, 30);
  insertarNodo(raiz, 10);
  insertarNodo(raiz, 2);
  printf("\nPreorden: \n");
  preorden(raiz);
  printf("\nInorden: \n");
  inorden(raiz);
  printf("\nPostorden: \n");
  postorden(raiz);
  printf("\nIniciando programa de busqueda. Para salir recuerda ingresar el numero '9999'\n");
  int x;
  do{
    x=0;
    printf("\nIngresa un numero para buscar su nivel: ");
    scanf("%d",&x);
    if(x!=9999){
      int nivel = buscar(raiz, x);
      if(nivel){
        printf("El numero %d esta en en nivel %d.\n",x,buscar(raiz,x));
      }else{
        printf("El numero %d no esta en el arbol...\n",x);
      }
    }
  }while(x!=9999);
  printf("\nHas ingresado el valor 9999...\n");
  printf("Estado: Saliendo del programa.\n\n");
  return 0;
}

//
//         1                  28
//                         /      \                .                            
//                        /        \
//         2            11          96
//                    /   \        /  \
//         3         6     21    30    97   
//                 /  \
//         4      1    10
//                 \               .
//         5        2
//
