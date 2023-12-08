#include<iostream>

#define MAX 100

using namespace std;

class Grafo {
    int matrizAdyacencia[MAX][MAX];
    int n; // Número de nodos en el grafo

public:
    Grafo(int nodos) { // Constructor
        n = nodos;
        // Inicializar la matriz de adyacencia con ceros
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                matrizAdyacencia[i][j] = 0;
            }
        }
    }

    void agregarArista(int u, int v) { // Función para agregar una arista al grafo
        matrizAdyacencia[u][v] = 1; // Agregar una arista del nodo u al nodo v
    }

    void imprimirGrafo() { // Función para imprimir el grafo
        // Recorrer la matriz 
        for(int i=0; i<n; i++) {
            cout << "Nodo " << i << " tiene una arista hacia: ";
            for(int j=0; j<n; j++) {
                // Si hay una arista del nodo i al nodo j
                if(matrizAdyacencia[i][j] == 1) {
                    cout << j << " "; // Imprimir el nodo j
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int nodos, opcion, u, v;

    cout << "Ingrese el número de nodos: ";
    cin >> nodos;

    Grafo g(nodos); // Crear un objeto de la clase Grafo

    while(1) { 
        cout << "1. Agregar arista\n2. Mostrar grafo\n3. Salir\n";
        cin >> opcion;

        switch(opcion) { 
            case 1: // Opción para agregar una arista
                cout << "Ingrese el nodo de origen y destino de la arista: ";
                cin >> u >> v;
                g.agregarArista(u, v); // Agregar la arista al grafo
                break;
            case 2: // Opción para imprimir el grafo
                g.imprimirGrafo(); 
                break;
            case 3: // Opción para salir del programa
                exit(0);
            default: 
                cout << "Opción inválida\n";
        }
    }

    return 0;
}
