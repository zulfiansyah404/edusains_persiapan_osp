#include<bits/stdc++.h>
using namespace std;

void printV(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;
}

int main () {
    vector<int> v;

    // Push Back
    v.push_back(1); // v = {1}
    v.push_back(10); // v = {1, 10}
    v.push_back(12); // v = {1, 10, 12}
    printV(v);

    // Pop Back
    v.pop_back(); // v = {1, 10}
    printV(v);

    // Insert
    v.insert(v.begin() + 1, 5); // v = {1, 5, 10}
    v.insert(v.end() - 1, 7); // v = {1, 5, 7, 10}
    printV(v);

    // Delete indeks ke-2
    v.erase(v.begin() + 2); // v = {1, 5, 10}
    printV(v);

    // Delete All
    v.clear(); // v = {}
    printV(v);

    // Size
    cout << v.size() << endl; // 0

    for (int i = 10; i >= 1; i--) {
        v.push_back(i);
    }

    // Sort
    sort(v.begin(), v.end()); // v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    printV(v);

    // isEmpty
    if (v.empty()) {
        cout << "Kosong" << endl;
    } else {
        cout << "tIDAK KOsong" << endl;
    }

}