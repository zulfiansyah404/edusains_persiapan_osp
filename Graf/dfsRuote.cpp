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
    stack<pair<int,string>> s;
    s.push(make_pair(node,""));

    while ((!s.empty()) && (s.top().first != finish)) {
        pair<int,string> top = s.top();
        s.pop();
        if (!visited[top.first]) {
            visited[top.first] = true;    
            for (auto adj : adjList[top.first]) {
                if (!visited[adj]) {
                    if (top.second == "") {
                        s.push(make_pair(adj, to_string(top.first)));
                    }
                    else {
                        s.push(make_pair(adj, top.second + " - " + to_string(top.first)));
                    }
                }
            }
        }

        // cout << "Sedang mengunjungi node " << top << endl;
        // cout << "Stack: ";
        // stack<int> temp = s;
        // printStack(temp);
        // cout << endl;
    }

    if (s.empty()) {
        cout << "Tidak ada rute" << endl;
    } else {
        string ans = s.top().second + " - " + to_string(s.top().first);
        cout << ans << endl;
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