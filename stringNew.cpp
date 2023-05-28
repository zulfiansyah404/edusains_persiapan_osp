#include<bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cout << "s = " << endl;
    getline(cin, s);

    cout << "s.length() = " << s.length() << endl;

    string s1;
    cout << "s1 = " << endl;
    getline(cin, s1);

    cout << "s1.length() = " << s1.length() << endl;
    cout << "s.find(s1) = " << s.find(s1) << endl;
    cout << "s.substr(2, 4) = " << s.substr(2,4) << endl;

    s.insert(4, " ");
    cout << "s.insert(4, \" \") = " << s << endl;

    // s.erase(2,4);
    // cout << "s.erase(2, 4) = " << s << endl;

    string s2 = s + " " + s1;

    cout << "s2 = " << s2 << endl;


}