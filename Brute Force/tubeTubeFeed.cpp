#include<bits/stdc++.h>
using namespace std;

void solve() {
    int N, T;
    cin >> N >> T;

    int a[N], b[N];

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    int idx = -1;

    for (int i = 0; i < N; i++) {
        if (i + a[i] <= T) {
            if ((idx == -1) || (b[idx] < b[i])) {
                idx = i;
            }
        }
    }

    if (idx == -1) {
        cout << idx << endl;
    } else {
        cout << idx+1 << endl;
    }
}

// Solve : https://codeforces.com/problemset/problem/1822/A
int main () {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        solve();
    }
}