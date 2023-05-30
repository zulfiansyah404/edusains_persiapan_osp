#include<bits/stdc++.h>
using namespace std;

int main () {
    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);

    cout << pq.top() << endl;
    
    pq.pop();
    cout << pq.top() << endl;

    if (pq.empty()) {
        cout << "kosong" << endl;
    } else {
        cout << "tidak kosong" << endl;
    }

    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(1);
    pq2.push(2);
    pq2.push(3);

    cout << pq2.top() << endl;
    
    pq2.pop();
    cout << pq2.top() << endl;

    if (pq2.empty()) {
        cout << "kosong" << endl;
    } else {
        cout << "tidak kosong" << endl;
    }
}