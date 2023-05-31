#include <bits/stdc++.h>
using namespace std;

int N, M, T;
int petak[500][500];
int sX, sY;
bool visited[500][500];

int solve(int a, int b) {
	if(a == 0 || b == 0 || a == N+1 || b == M+1) {
		return 0;
	}

	// Petaknya batu	
	if(petak[a][b] == 1) {
		return 0;
	}
	
	// Kalau udah pernah dikunjungi
	if(visited[a][b]) {
		return 0;
	}
	

	visited[a][b] = true;
	

	int hasil = solve(a, b+1) + solve(a, b-x1) + solve(a+1, b) + solve(a-1, b);
	
	if(petak[a][b] == 2) {
		petak[a][b] = 0;
		return hasil + 1;
	}
	
	return hasil;
}

int main() {
	cin >> N >> M >> T;
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			cin >> petak[i][j];
		}
	}
	
	for(int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;
		petak[a][b] = 2;
	}
	
	cin >> sX >> sY;

	cout << solve(sX, sY);
}