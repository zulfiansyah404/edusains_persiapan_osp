#include<bits/stdc++.h>
using namespace std;

int main () {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.top() << endl;
    
    s.pop();
    cout << s.top() << endl;

    if (s.empty()) {
        cout << "kosong" << endl;
    } else {
        cout << "tidak kosong" << endl;
    }

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.front() << endl;

    q.pop();

    cout << q.front() << endl;

    if (q.empty()) {
        cout << "kosong" << endl;
    } else {
        cout << "tidak kosong" << endl;
    }

}