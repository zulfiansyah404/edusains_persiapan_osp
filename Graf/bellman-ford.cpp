#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int node1;
    int node2;
    int weight;
};


bool visited[1000];
int V, E;          // Banyaknya node/vertex dan banyaknya edge
vector<Edge> edges;
int dist[1000];

void fillArray(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}

void bellmanFord(int start) {
    fillArray(dist, V, INT_MAX);

    dist[start] = 0;

    for (int i = 0; i < V-1; i++) {
        for (auto x : edges) {
            if (dist[x.node2] > dist[x.node1] + x.weight) {
                dist[x.node2] = dist[x.node1] + x.weight;
            }
        }
    }
}

bool hasNegativeCycle() {
    for (auto x : edges) {
        if (dist[x.node2] > dist[x.node1] + x.weight) {
            return true;
        }
    }
    return false;
}

int main() {

    cin >> V >> E;

    // Membaca input edge
    for (int i = 0; i < E; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        // Menandai bahwa ada edge dari a ke b
        Edge e;
        e.node1 = a;
        e.node2 = b;
        e.weight = w;

        edges.push_back(e);
    }

    int start;
    cin >> start;

    bellmanFord(start);

    for (int i = 0; i < V; i++) {
        cout << "dist[" << i << "] = " << dist[i] << endl;
    }

}