#include<bits/stdc++.h>
using namespace std;

int N, coin[1000], M;

bool visited[1000];
int memo[1000];

int solveTopDown(int x) {
    if (x == 0) {
        return 0;
    }

    if (visited[x]) {
        return memo[x];
    }

    int best = 1e9;
    for (int i = 0; i < N; i++) {
        if (x >= coin[i]) {
            best = min(best, solveTopDown(x - coin[i]) + 1);
        }
    }

    visited[x] = true;
    memo[x] = best;

    return best;
}

int main () {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    cin >> M;

    cout << solveTopDown(M) << endl;
}