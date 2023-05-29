#include<bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;

        int dist = x*x + y*y;

        int idx = 1;
        while (idx*idx < dist) {
            idx++;
        }

        if (x == 0 && y == 0) {
            cout << 0 << endl;
        } else
        if (idx*idx == dist) {  
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
}