#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    int jumlah_faktor = 1;

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            jumlah_faktor += i + n/i;
        }
    }

    if (jumlah_faktor == n) {
        cout << "Sempurna" << endl;
    } else
    if (jumlah_faktor < n) {
        cout << "Defisit" << endl;
    } else {
        cout << "Surplus" << endl;
    }


}