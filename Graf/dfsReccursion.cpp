#include<bits/stdc++.h>
using namespace std;

bool visited[1000];
int V, E;          // Banyaknya node/vertex dan banyaknya edge
vector<int> adj[1000];

void dfs(int node, int kedalaman) {
    for (int i = 0; i < kedalaman; i++) {
        cout << " ";
    }
    cout << "Sedang mengunjungi node " << node << endl;

    visited[node] = true;

    for (auto x : adj[node]) {
        if (!visited[x]) {
            dfs(x, kedalaman+1);
        }
    }
}


int main() {

    cin >> V >> E;

    // Membaca input edge
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // DFS
    dfs(0, 0);

    
}