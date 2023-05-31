#include<bits/stdc++.h>
using namespace std;

bool visited[1000];
int V, E;          // Banyaknya node/vertex dan banyaknya edge
vector<int> adjList[1000];

// void printStack(stack<int> s) {
//     // stack<int> temp = s;
//     vector<int> v;
//     while (!s.empty()) {
//         cout << s.top() << " ";
//         s.pop();
//     }
// }
bool pertama = true;
void dfs(int node, int kelar) {
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
    if (pertama) {
        cout << top << " > ";
        pertama = false;
    }
    else {
        if (top == kelar) {
            cout << top;
            break;
        }
        else cout << top << " > ";
    }
    }
}


int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int start, finish;
    cin >> start >> finish;
    dfs(start, finish);
}