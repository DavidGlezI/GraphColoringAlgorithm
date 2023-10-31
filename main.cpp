#include <iostream>
#include <vector>



std::vector<std::vector<int>> adj{
    {0,1,1,0,0},
    {1,0,1,1,0},
    {1,1,0,1,0},
    {0,1,1,0,1},
    {0,0,0,1,0}
};

std::vector<int> GraphColoring(int V, std::vector<std::vector<int>>& adj){
    std::vector<bool> colorDisponible(V, true); // Ponemos todos los colores disponibles en un principio
    std::vector<int> resultados(V, -1);

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
    int ver = 5;

    std::vector<int> resultados = GraphColoring(ver, adj);
    for (int i = 0; i < ver; i++){
        std::cout << "Node: " << i << ", Assigned Color: "<< resultados[i] << std::endl;
    }
        
    return 0;
}