#include<bits/stdc++.h>
using namespace std;

bool visited[1000];
int V, E;          // Banyaknya node/vertex dan banyaknya edge
vector<pair<int,int>> edgeList;


int main() {

    cin >> V >> E;

    // Membaca input edge
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;

        edgeList.push_back(make_pair(a,b));
    }

    for (auto x : edgeList) {
        cout << x.first << " " << x.second << endl;
    }

    
}