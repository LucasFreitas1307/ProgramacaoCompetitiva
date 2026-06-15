#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Estrada {
    int cidade_destino;
    long long comprimento;
};


int total_cidades, total_estradas;
vector<vector<Estrada>> grafo;
vector<bool> visitado;
long long maior_comprimento_total = 0;

void buscar_maior_caminho(int cidade_atual, long long comprimento_acumulado) {
    maior_comprimento_total = max(maior_comprimento_total, comprimento_acumulado);

 
    for (const auto& estrada : grafo[cidade_atual]) {
        int proxima_cidade = estrada.cidade_destino;

       
        if (!visitado[proxima_cidade]) {
            visitado[proxima_cidade] = true; 
            
            buscar_maior_caminho(proxima_cidade, comprimento_acumulado + estrada.comprimento);
            
            visitado[proxima_cidade] = false; 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> total_cidades >> total_estradas)) return 0;

    grafo.assign(total_cidades + 1, vector<Estrada>());
    visitado.assign(total_cidades + 1, false);

    for (int i = 0; i < total_estradas; ++i) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        
       
        grafo[u].push_back({v, c});
        grafo[v].push_back({u, c});
    }

 
    for (int i = 1; i <= total_cidades; ++i) {
        visitado[i] = true; 
        buscar_maior_caminho(i, 0);
        visitado[i] = false; 
    }

   
    cout << maior_comprimento_total << "\n";

    return 0;
}
