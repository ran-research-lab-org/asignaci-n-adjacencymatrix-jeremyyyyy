#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    // Crea un vector de 2D n x n
    Graph(int n) : numVertices(n), adjMatrix(n, std::vector<int>(n, 0)) {}

    // Add a vertex from node u to node v
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjMatrix[u][v] = 1;
        } else {
            std::out_of_range("Vertice fuera de rango");
        }
    }

    // Imprime la matriz de adyacencias
    void print() const {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Implementar!! 
    // Devuelve la cantidad de aristas
    int numEdges() const { 
        int counter = 0; // variable para acumular la cantidad de aristas 
        // recorremos la matriz
        for (int i = 0; i < numVertices; ++i) { 
            for (int j = 0; j < numVertices; ++j) {
               if (adjMatrix[i][j] == 1) 
                    counter += 1; // sumamos 1 cada vez que se encuentra una arista
            }
        }
        return counter; // devolvemos la cantidad de aristas 
    }

    // Completa esta función
    // Devuelve el in-degree de un vertice
    int inDegree(int u) const {
        if (u < 0 || u >= numVertices)
            throw std::out_of_range("Vertice fuera de rango");
        else {
            int InDegreeCounter = 0; // variable para contar las aristas que llegan al vertice U
            // recorremos la columna del vertice U
            for (int i = 0; i < numVertices; ++i) {
                if (adjMatrix [i][u] == 1)
                InDegreeCounter += 1; // sumamos 1 cada vez que se encuentra una arista entrante
            }
            return InDegreeCounter; // devolvemos el in-degree del vertice U
        }   
    }

    // Completa esta función
    // Devuelve cierto si u es el nodo con mayor inDegree.
    // En caso de que haya varios nodos que tengan el mayor inDegree,
    // devuelve true si u es uno de ellos
    bool isInfluencer(int u) const  {     
        if (u < 0 || u >= numVertices)
            throw std::out_of_range("Vertice fuera de rango");
        // recorremos la columna del vertice U 
        int UCounter = 0; // variable para contar las aristas entrantes del vertice U         
        for (int i = 0; i < numVertices; ++i) {
            if (adjMatrix [i][u] == 1)
                UCounter += 1; // sumamos 1 cada vez que se encuentra una arista entrante 
        }
        // recorremos todos los vertices
        int Influencer = 0; // variable que guarda la cantidad de aristas entrantes del vertice que mas tenga           
        for (int i = 0; i < numVertices; ++i) {
            int InfluencerCounter = 0; // variable que cuenta la cantidad de aristas entrantes del vertice actual
            for (int j = 0; j < numVertices; ++j) {
                if (adjMatrix[j][i] == 1)
                    InfluencerCounter += 1; // sumamos 1 si se encuentra una arista entrante en el vertice actual
            }
                if (InfluencerCounter > Influencer) // si la cantidad de aristas entrantes del vertice actual es mayor que el maximo encontrado
                    Influencer = InfluencerCounter; // actualizamos el maximo
            }
            return UCounter == Influencer; // Devuelve true si el vertice U es influencer, false otherwise           
        }    
};

