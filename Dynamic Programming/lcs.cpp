#include<bits/stdc++.h>
using namespace std;

struct info_barang {
    int harga;
    int berat;
};

string a, b;
int N_a, N_b;

bool visited[1000][1000];
int memo[1000][1000];

// int solveBottomUp() {
//     int fx[N+1][W+1];

//     for (int i = 0; i <= N; i++) {
//         for (int j = 0; j <= W; j++) {
//             if (i == 0 || j == 0) {
//                 fx[i][j] = 0;
//             } else {
//                 fx[i][j] = fx[i-1][j];
//                 if (j >= barang[i-1].berat) {
//                     fx[i][j] = max(fx[i][j], fx[i-1][j - barang[i-1].berat] + barang[i-1].harga);
//                 }
//             }
//         }
//     }

//     return fx[N][W];
// }

int solveTopDown(int i, int j) {
    if (i == N_a || j == N_b) {
        return 0;
    }

    if (visited[i][j]) {
        return memo[i][j];
    }

    int best = 0;
    if (a[i] == b[j]) {
        best = max(solveTopDown(i+1, j), solveTopDown(i, j+1));
        best = max(best, solveTopDown(i+1, j+1) + 1);
    } else {
        best = max(solveTopDown(i+1, j), solveTopDown(i, j+1));
    }

    visited[i][j] = true;
    memo[i][j] = best;

    return best;
}

int main () {
    
    getline(cin, a);
    getline(cin, b);

    N_a = a.length();
    N_b = b.length();

    cout << solveTopDown(0, 0) << endl;
}