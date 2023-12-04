#include <iostream>
#include <conio.h>

using namespace std;

// Definición de la estructura Nodo para el árbol binario
struct Nodo {
    int dato;
    Nodo *der;
    Nodo *izq;
};

// Prototipos de funciones
Nodo *crearNodo(int);
Nodo* insertarNodoEquilibrado(int valores[], int inicio, int fin);
void Menu();
void mostrarArbol(Nodo *, int);
void liberarArbol(Nodo *);

// Puntero al nodo raíz del árbol
Nodo *arbol = NULL;

int main() {
    Menu();
    liberarArbol(arbol);
    return 0;
}

// Función que muestra un menú interactivo
void Menu() {
    int opcion, numNodos;

    cout << "Ingrese el número de nodos para el árbol: ";
    cin >> numNodos;

    int valores[numNodos];
    cout << "Ingrese los valores ordenados para construir el árbol: ";
    for (int i = 0; i < numNodos; ++i) {
        cin >> valores[i];
    }

    // Construir un árbol binario equilibrado
    arbol = insertarNodoEquilibrado(valores, 0, numNodos - 1);

    do {
        system("cls");
        cout << "\n\tMENU" << endl;
        cout << "\n\t1.- Mostrar árbol.\n\t2.- Salir.\n\t";
        cout << "Opcion:\t";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Mostrar el árbol en la consola
                cout << "\n\tMostrando árbol:\n\n";
                mostrarArbol(arbol, 0);
                cout << "\n";
                cin.ignore();  // Esperar la entrada del usuario
                system("pause");
                break;
        }
    } while (opcion != 2);
}

// Función que crea un nuevo nodo con un valor dado
Nodo *crearNodo(int n) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    return nuevo_nodo;
}

// Función que inserta nodos en el árbol de manera equilibrada
Nodo* insertarNodoEquilibrado(int valores[], int inicio, int fin) {
    if (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        Nodo* nuevo_nodo = crearNodo(valores[medio]);

        // Insertar nodos en los subárboles izquierdo y derecho
        nuevo_nodo->izq = insertarNodoEquilibrado(valores, inicio, medio - 1);
        nuevo_nodo->der = insertarNodoEquilibrado(valores, medio + 1, fin);

        return nuevo_nodo;
    } else {
        return NULL;  // Retornar NULL para indicar una hoja en el árbol
    }
}

// Función que muestra el árbol de manera recursiva
void mostrarArbol(Nodo *arbol, int cont) {
    if (arbol == NULL) {
        return;
    } else {
        // Mostrar el subárbol derecho
        mostrarArbol(arbol->der, cont + 1);

        // Imprimir espacios proporcionales a la profundidad del nodo
        for (int i = 0; i < cont; i++) {
            cout << "   ";
        }

        // Imprimir el valor del nodo
        cout << arbol->dato << endl;

        // Mostrar el subárbol izquierdo
        mostrarArbol(arbol->izq, cont + 1);
    }
}

// Función que libera la memoria asignada para el árbol
void liberarArbol(Nodo *arbol) {
    if (arbol != NULL) {
        liberarArbol(arbol->izq);
        liberarArbol(arbol->der);
        delete arbol;  // Liberar el nodo actual
    }
}
