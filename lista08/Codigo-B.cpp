#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visitado;

void dfs(int u) {
    visitado[u] = true;
    for (int v : adj[u]) {
        if (!visitado[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visitado.assign(n + 1, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> representantes;

    for (int i = 1; i <= n; i++) {
        if (!visitado[i]) {
            representantes.push_back(i);
            dfs(i);
        }
    }
    int k = representantes.size() - 1;
    cout << k << "\n";
    for (int i = 0; i < k; i++) {
        cout << representantes[i] << " " << representantes[i + 1] << "\n";
    }

    return 0;
}
