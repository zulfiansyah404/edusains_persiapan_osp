#include<bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;

    int arr[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Cari nilai terbesar
    int idxMax = 0;

    for (int i = 1; i < N; i++) {
        if (arr[i] >= arr[idxMax]) {
            idxMax = i;
        }
    }

    cout << "maks = " << arr[idxMax] << endl;
    cout << "Idx = " << idxMax << endl;
}