#include<bits/stdc++.h>
using namespace std;

int N, K, arr[10000];

int pemanggilanSolve = 0;

bool solve(int idx, int sum) {
    pemanggilanSolve++;
    if (idx == N) {
        return sum == K;
    }

    bool solve1 = solve(idx + 1, sum + arr[idx]);
    bool solve2 = solve(idx + 1, sum);

    return solve1 || solve2;
}


int main () {
    cout << "N = ";
    cin >> N;

    for (int i = 0; i < N;i++) {
        // input random
        arr[i] = rand() % 1000;
    }

    cin >> K;

    if (solve(0, 0)) {
        cout << "Ada" << endl;
    } else {
        cout << "Tidak ada" << endl;
    }

    cout << "Pemanggilan solve = " << pemanggilanSolve << endl;
}