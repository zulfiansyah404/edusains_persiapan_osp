#include<bits/stdc++.h>
using namespace std;

bool visited[1000];
int V, E;          // Banyaknya node/vertex dan banyaknya edge
int adjMatrix[1000][1000]; // Adjacency Matrix

bool jelajah(int nodeA, int nodeB) {
    cout << "Jelajah node " << nodeA << endl;
    if (adjMatrix[nodeA][nodeB] == 1) {
        return true;
    }

    if (visited[nodeA]) {
        return false;
    }

    visited[nodeA] = true;

    bool found = false;
    for (int i = 0; i < V; i++) {
        if (adjMatrix[nodeA][i] == 1)
            found = found || jelajah(i, nodeB);
    }

    return found;

}


int main() {

    cin >> V >> E;



    // Inisialisasi adjacency matrix dengan 0
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Membaca input edge
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;

        // Menandai bahwa ada edge dari a ke b
        adjMatrix[a][b] = 1;
        adjMatrix[b][a] = 1;
    }

    int Q;
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        memset(visited, false, sizeof(visited));

        int a, b;
        cin >> a >> b;

        if (jelajah(a, b)) {
            cout << "Ada" << endl;
        } else {
            cout << "Tidak Ada" << endl;
        }
    }
}