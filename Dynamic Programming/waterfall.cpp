#include<bits/stdc++.h>
using namespace std;

int V, H, N;

struct koor_batu {
    int x1;
    int x2;
    int y1;
    int y2;
};

koor_batu listBatu[290000];

bool visited[1000][1000];
long long memo[1000][1000];

int batu[600][600];

long long solve(int x, int y) {
    // cout << "   solve(" << x << "," << y <<")" << endl;
    if (x == V || y == 0 || y > H) {
        return 0;
    }

    if (visited[x][y]) {
        return memo[x][y];
    }

    long long best = 0;
    if (batu[x+1][y] == 0) {
        best = solve(x+1, y);
    } else {
        // Untuk arah kiri
        int kiri = y-1;
        while (batu[x+1][kiri] != 0 && kiri > 0) {
            kiri--;
        }
        int kanan = y+1;
        while (batu[x+1][kanan] != 0 && kanan <= H) {
            kanan++;
        }

        best = solve(x+1, kiri) + solve(x+1, kanan) + 1;
    }

    visited[x][y] = true;
    memo[x][y] = best;

    return best;
}


int main () {
    cin >> V >> H >> N;
    for (int i = 0; i < N; i++) {
        cin >> listBatu[i].x1 >> listBatu[i].y1 >> listBatu[i].x2 >> listBatu[i].y2;
    }



    // Bikin dulu map
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= H; j++) {
            batu[i][j] = 0;
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = listBatu[i].x1; j <= listBatu[i].x2; j++) {
            for (int k = listBatu[i].y1; k <= listBatu[i].y2; k++) {
                batu[j][k] = i+1;
            }
        }
    }

    long long best = 0;
    for (int i = 1; i <= H; i++) {
        // cout << "Y = " << i << endl;
        best = max(best, solve(0, i));
    }

    cout << best << endl;




}