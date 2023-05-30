#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int jam, menit;
    scanf("%d:%d", &jam, &menit);

    double sudut_jam = (jam % 12) * 30 + menit * 0.5;

    double sudut_menit = menit * 6;

    double selisih = abs(sudut_jam - sudut_menit);

    if (selisih > 180) {
        selisih = 360 - selisih;
    }

    printf("%.2lf\n", selisih);
}