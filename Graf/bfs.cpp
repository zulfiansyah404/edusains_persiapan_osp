#include<bits/stdc++.h>
using namespace std;

bool visited[1000];
int V, E;          // Banyaknya node/vertex dan banyaknya edge
vector<int> adjList[1000];

void printQueue(queue<int> s) {
    // stack<int> temp = s;
    vector<int> v;
    while (!s.empty()) {
        cout << s.front() << " ";
        s.pop();
    }
}

void bfs(int node) {
    queue<int> q;
    q.push(node);

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        if (!visited[top]) {
            visited[top] = true;    
            for (auto adj : adjList[top]) {
                if (!visited[adj]) {
                    q.push(adj);
                }
            }
        }

        cout << "Sedang mengunjungi node " << top << endl;
        cout << "Stack: ";
        queue<int> temp = q;
        printQueue(temp);
        cout << endl;
    }
}


int main() {

    cin >> V >> E;

    // Membaca input edge
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int start;
    cin >> start;

    // Kalian print rutenya

    // DFS
    bfs(start);

    
}