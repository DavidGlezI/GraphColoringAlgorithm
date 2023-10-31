#include <iostream>
#include <vector>

using namespace std;

// Actividad 3.4 Implementación de "Graph coloring"
// Rogelio Guzman Cruzado - A01639914
// David Alejandro González Ibarra - A01633817


// Complejidad temporal: O(V^2)
std::vector<int> GraphColoring(int V, std::vector<std::vector<int>>& adj){
    std::vector<bool> colorDisponible(V, true); // Ponemos todos los colores disponibles en un principio
    std::vector<int> resultados(V, 0);

    resultados.insert(resultados.begin(),0); // Inicializamos el primer vertice con el primer color (0)

    for(int vertice=1; vertice< V; vertice++){ // Iteramos en los demás vertices

        for(int j=0; j<V; j++){
            if(adj[vertice][j] != 0){ 
            // Checamos las conexiones en ese vertice. Por cada color que este marcado, los vamos poniendo como false
            // en la lista de colorDisponible.
                colorDisponible[resultados[j]] = false;
            }
        }
        // Revisamos la lista de colores para buscar el primer color que este disponible (el mas bajo)
        int color;
        for(color = 0; color<V; color++){
            if(colorDisponible[color]== true){
                break; // Si esta disponible, salimos y nos quedamos con el indice del color en la variable para asignarlo
            }
        }

        resultados[vertice] = color; // Lo asignamos

        for(int j=0; j<V; j++){
            if(adj[vertice][j] != 0){ 
            // Checamos las conexiones en ese vertice. Por cada color que este marcado, los vamos poniendo como false
            // en la lista de colorDisponible.
                colorDisponible[resultados[j]] = true;
            }
        }
    }
    return resultados;
}

int main(){
    int ver;
    cin >> ver;
    std::vector<std::vector<int>> adj(ver, std::vector<int>(ver));

    for(int i = 0; i < ver; i++){
        for(int j = 0; j < ver; j++){
            int num;
            cin >> num;
            adj[i][j] = num;
        }
    }

    std::vector<int> resultados = GraphColoring(ver, adj);
    for (int i = 0; i < ver; i++){
        std::cout << "Node: " << i << ", Assigned Color: "<< resultados[i] << std::endl;
    }
        
    return 0;
}