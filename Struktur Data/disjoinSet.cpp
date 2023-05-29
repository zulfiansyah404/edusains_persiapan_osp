#include<bits/stdc++.h>
using namespace std;

int par[100000];

int findRepresentative(int x) {
    if (par[x] == x) {
        return x;
    } else {
        par[x] = findRepresentative(par[x]);
        return par[x];
    }
}

void inisialisasi() {
    for (int i = 0; i < 100000; i++) {
        par[i] = i;
    }
}

void join(int a, int b) {
    int repA = findRepresentative(a);
    int repB = findRepresentative(b);
    par[repA] = repB;
}

bool check(int a, int b) {
    return findRepresentative(a) == findRepresentative(b);
}

int main () {
    inisialisasi();
    int x;
    cin >> x;
    while (x != 0) {
        if (x == 1) {
            int a, b;
            cin >> a >> b;
            join(a, b);
        } else {
            int a, b;
            cin >> a >> b;
            if (check(a, b)) {
                cout << "sama" << endl;
            } else {
                cout << "beda" << endl;
            }
        }

        cin >> x;
    }

    for (int i = 0; i < 10; i++) {
        cout << par[i] << " ";
    }
}