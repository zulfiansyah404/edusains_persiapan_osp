#include<bits/stdc++.h>
using namespace std;

bool visited[1000];
int V, E;          // Banyaknya node/vertex dan banyaknya edge
vector<int> adjList[1000];

void printStack(stack<int> s) {
    // stack<int> temp = s;
    vector<int> v;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

void dfs(int node, int finish) {
    stack<int> s;
    s.push(node);

    while (!s.empty()) {
        int top = s.top();
        s.pop();
        if (!visited[top]) {
            visited[top] = true;    
            for (auto adj : adjList[top]) {
                if (!visited[adj]) {
                    s.push(adj);
                }
            }
        }

        cout << "Sedang mengunjungi node " << top << endl;
        cout << "Stack: ";
        stack<int> temp = s;
        printStack(temp);
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
    int finish;
    cin >> start >> finish;

    // Kalian print rutenya

    // DFS
    dfs(start, finish);

    
}