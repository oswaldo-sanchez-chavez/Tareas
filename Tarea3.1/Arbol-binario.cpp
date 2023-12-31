#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

// Definición de la estructura Nodo para el árbol binario
struct Nodo {
    int dato;
    Nodo *der;
    Nodo *izq;
};

// Prototipos de funciones
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void Menu();
void mostrarArbol(Nodo *, int);

// Puntero al nodo raíz del árbol
Nodo *arbol = NULL;

int main(){
    // Iniciar el menú principal
    Menu();
    return 0;
}

// Función que muestra un menú interactivo
void Menu(){
    int dato, opcion, contador=0;
    
    do {
        // Menú principal
        cout << "\n\tMENU" << endl;
        cout << "\n\t1.- Insertar nuevo nodo.\n\t2.- Mostrar arbol.\n\t3.- Salir.\n\t";
        cout << "Opcion:\t";
        cin >> opcion;
        
        switch(opcion){
            case 1: {
                // Insertar un nuevo nodo
                cout << "\n\tDigita un numero:\t";
                cin >> dato;
                insertarNodo(arbol, dato);
                cout << "\n";
                system("pause");
                break;
            }
            case 2: {
                // Mostrar el árbol
                cout << "\n\tMostrando arbol:\n\n";
                mostrarArbol(arbol, contador);
                cout <<"\n";
                system("pause");
                break;
            }
        }
        // Limpiar la pantalla antes de repetir el ciclo
        system("cls");
    } while(opcion != 3);
}

// Función que crea un nuevo nodo con un valor dado
Nodo *crearNodo(int n){
    Nodo *nuevo_nodo = new Nodo();
    
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    
    return nuevo_nodo;
} 

// Función que inserta un nuevo nodo en el árbol
void insertarNodo(Nodo *&arbol, int n){
    if(arbol == NULL){
        // Si el árbol está vacío, crea un nuevo nodo y lo asigna como raíz
        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }
    else{
        // Si el árbol no está vacío, compara el valor y decide en qué rama insertar
        int valorRaiz = arbol->dato;
        if(n < valorRaiz){
            insertarNodo(arbol->izq, n);
        }
        else{
            insertarNodo(arbol->der, n);
        }
    }
}

// Función que muestra el árbol de manera recursiva
void mostrarArbol(Nodo *arbol, int cont){
    if(arbol == NULL){
        return;
    }
    else{
        // Mostrar el subárbol derecho
        mostrarArbol(arbol->der, cont + 1);
        
        // Imprimir espacios proporcionales a la profundidad del nodo
        for(int i = 0; i < cont; i++){
            cout << "   ";
        }
        
        // Imprimir el valor del nodo
        cout << arbol->dato << endl;
        
        // Mostrar el subárbol izquierdo
        mostrarArbol(arbol->izq, cont + 1);
    }
}
