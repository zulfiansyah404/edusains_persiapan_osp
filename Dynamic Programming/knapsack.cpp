#include<bits/stdc++.h>
using namespace std;

struct info_barang {
    int harga;
    int berat;
};

int N;
int W;
info_barang barang[1000];

bool visited[1000][1000];
int memo[1000][1000];

int solveBottomUp() {
    int fx[N+1][W+1];

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                fx[i][j] = 0;
            } else {
                fx[i][j] = fx[i-1][j];
                if (j >= barang[i-1].berat) {
                    fx[i][j] = max(fx[i][j], fx[i-1][j - barang[i-1].berat] + barang[i-1].harga);
                }
            }
        }
    }

    return fx[N][W];
}

int solveTopDown(int idx, int w) {
    if (idx == N) {
        return 0;
    }

    if (visited[idx][w]) {
        return memo[idx][w];
    }

    int best = solveTopDown(idx+1, w);

    if (w >= barang[idx].berat) {
        best = max(best, solveTopDown(idx+1, w - barang[idx].berat) + barang[idx].harga);
    }
    
    visited[idx][w] = true;
    memo[idx][w] = best;

    return best;
}

int main () {
    cin >> N >> W;

    for (int i = 0; i < N; i++) {
        cin >> barang[i].harga >> barang[i].berat;
    }
    
    cout << solveTopDown(0, W) << endl;

    cout << solveBottomUp() << endl;

}