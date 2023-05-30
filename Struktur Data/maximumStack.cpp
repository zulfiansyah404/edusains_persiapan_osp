#include<bits/stdc++.h>
using namespace std;

vector<int> getMax(vector<string> operation) {
    vector<int> s;
    vector<int> ans;

    // int Q = operation.size();
    for (auto q : operation) {
        if (q[0] == '1') {
            int x = stoi(q.substr(2));
            s.push_back(x);
        } else
        if (q[0] == '2') {
            s.pop_back();
        } else {
            int mx = 0;
            for (auto x : s) {
                mx = max(mx, x);
            }
            ans.push_back(mx);
        }
    }

    return ans;
}
int main () {
    int N;
    cin >> N;

    vector<string> operation;

    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        operation.push_back(s);
    }

    vector<int> ans = getMax(operation);

    for (auto x : ans) {
        cout << x << endl;
    }
}