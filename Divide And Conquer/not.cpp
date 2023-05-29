/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #87 (Div. 1 Only)
*/
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int64;

int64 N;
int Q, MOD;
int64 beg, en, lb, ub;

// (f + 0*gap) + (f + 1*gap) + (f + 2*gap) + ... + (f + n*gap)
int64 sum(int64 f, int64 gap, int64 n)
{
	n++;
	n %= MOD;
	f %= MOD;
	gap %= MOD;

	return (n * f % MOD + (n * (n - 1)/2) % MOD * gap) % MOD;
}

int64 solve(int64 lo, int64 hi, int64 roof, int64 first = 1, int64 gap = 1)
{
    cout << lo << " " << hi << " " << roof << " " << first << " " << gap << endl;
	if (lo > hi) return 0;
	if (lo > en || hi < beg) return 0;

	if (first > roof) return 0;

	if (lo >= beg && hi <= en)
	{
		int64 p = (roof - first) / gap;
	      p = min(p, hi - lo);
	      return sum(first, gap, p);
	}

	int64 mid = (lo + hi) / 2;

	return
		(solve(lo, mid, roof, first, gap * 2) +
 		solve(mid + 1, hi, roof, first + gap, gap * 2)) % MOD;
}

int main()
{
	cin >> N >> Q >> MOD;
	while (Q--)
	{
		cin >> beg >> en >> lb >> ub;
		cout << (solve(1, N, ub) - solve(1, N, lb - 1) + MOD) % MOD << endl;
	}

	return 0;
}