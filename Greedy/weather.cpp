#include<bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;

    while (--t) {
        int n;

        cin >> n;

        pair<int, int> a[n];
        int b[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i; 
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        sort(a, a+n);
        sort(b, b+n);

        int ans[n];

        for (int i = 0; i < n; i++) {
            ans[a[i].second] = b[i];
        }
    }
}