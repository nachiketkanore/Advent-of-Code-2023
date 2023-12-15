/**
 *    Author: Nachiket Kanore
 *    Created: Friday 15 December 2023 11:55:41 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

int solve(const string& A) {
	int hash = 0;
	for (char ch : A) {
		hash = (hash + int(ch)) * 17;
		hash %= 256;
	}
	return hash;
}

int32_t main() {
	string line;
	cin >> line;
	int ans = 0;
	string curr;
	for (char ch : line) {
		if (ch == ',') {
			ans += solve(curr);
			curr.clear();
		} else {
			curr += ch;
		}
	}
	ans += solve(curr);
	cout << ans;
}
