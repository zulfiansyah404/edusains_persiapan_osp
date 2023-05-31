#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int node;
    int weight;
};

bool visited[1000];
int V, E;          // Banyaknya node/vertex dan banyaknya edge
vector<Edge> adj[1000]; // Adjacency lIST
int dist[1000];

#define mp(a, b) make_pair(a, b)

void fillArray(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}

int dijkstra(int start, int finish) {
    // Isi seluruh dist dengan nilai tak hingga
    fillArray(dist, V, INT_MAX);
    memset(visited, false, sizeof(visited));

    dist[start] = 0;

    // Inisialisasi priority queue
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // Awal-awal masukkan start ke priority queue
    pq.push(mp(0, start));

    while (!pq.empty()) {
        // Proses node dengan jarak terdekat
        pair<int, int> top = pq.top();
        pq.pop();

        int node = top.second;
        int curDist = top.first;
        cout << "node = " << node << ", curDist = " << curDist << endl;


        // Jika node sudah dikunjungi, maka abaikan
        if (!visited[node]) {
            visited[node] = true;

            // Proses Relax ke semua tetangga dari node yang dikunjungi sekarang
            for (auto adjNode : adj[node]) {
                if (dist[adjNode.node] > curDist + adjNode.weight) {
                    dist[adjNode.node] = curDist + adjNode.weight;
                    pq.push(mp(dist[adjNode.node], adjNode.node));
                }
            }
        }

                cout << "node = " << node << ", curDist = " << curDist << endl;
        for (int i = 0; i < V; i++) {
        cout << "dist[" << i << "] = " << dist[i] << endl;
        }
        cout << "----------------------" << endl;   
    }

    return dist[finish];
}


int main() {

    cin >> V >> E;

    // Membaca input edge
    for (int i = 0; i < E; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        // Menandai bahwa ada edge dari a ke b
        Edge A, B;
        A.node = a;
        A.weight = w;

        B.node = b;
        B.weight = w;

        adj[a].push_back(B); 
        adj[b].push_back(A);
    }

    int start, finish;
    cin >> start >> finish;

    cout << dijkstra(start, finish) << endl;

    for (int i = 0; i < V; i++) {
        cout << "dist[" << i << "] = " << dist[i] << endl;
    }

}