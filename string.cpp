#include<bits/stdc++.h>
using namespace std;
#define forup(a,b) for(int i = a; i < b; i++) 
#define forup2(a,b) for(int j = a; j < b; j++) 
#define mp(a,b)	make_pair(a,b)
#define iPair pair<int,int>
#define pb push_back

typedef long long ll;

int main() {
    char s[10000], s1[10000];
    // scanf("%s", s);
    // getline(cin, s);
    cout << "Input s : " << endl;
    cin.getline(s, 10000);

    cout << "Panjang = " << strlen(s) << endl;

    strcpy(s1, s);

    cout << "s1 = " << s1 << endl;

    char s2[10000];
    cout << "Input s2 : " << endl;
    cin.getline(s2, 10000);

    cout << "strcmp =  " << strcmp(s1, s2) << endl;


    strrev(s2);
    cout << "Reserved S2 : " << s2 << endl;

}