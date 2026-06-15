#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Aresta {
    int u;
    int v;
};


int contar_vertices_alcancaveis(int total_vertices, const vector<vector<int>>& grafo) {
    vector<bool> visitado(total_vertices + 1, false);
    queue<int> fila;


    fila.push(1);
    visitado[1] = true;
    int contagem = 1;

    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();

        for (int vizinho : grafo[atual]) {
            if (!visitado[vizinho]) {
                visitado[vizinho] = true;
                contagem++;
                fila.push(vizinho);
            }
        }
    }
    return contagem;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Aresta> lista_arestas(m);
    for (int i = 0; i < m; ++i) {
        cin >> lista_arestas[i].u >> lista_arestas[i].v;
    }

    int total_pontes = 0;


    for (int i = 0; i < m; ++i) {

        vector<vector<int>> grafo_modificado(n + 1);

        for (int j = 0; j < m; ++j) {
            if (i == j) continue;

            int u = lista_arestas[j].u;
            int v = lista_arestas[j].v;
            grafo_modificado[u].push_back(v);
            grafo_modificado[v].push_back(u);
        }

        if (contar_vertices_alcancaveis(n, grafo_modificado) < n) {
            total_pontes++;
        }
    }

    cout << total_pontes << "\n";

    return 0;
}
