#include<bits/stdc++.h>
using namespace std;

int arr[10000];
int N;

int maxSearch(int l, int r) {
    if (l == r) {
        return arr[l];
    }

    int mid = (l+r)/2;

    int leftMax = maxSearch(l, mid);
    int rightMax = maxSearch(mid+1, r);

    return max(leftMax, rightMax);
}

int main () {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << maxSearch(0, N-1) << endl;

}