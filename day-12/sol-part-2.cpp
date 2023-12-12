/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 12 December 2023 06:38:56 PM IST
 **/
#include "bits/stdc++.h"
#include <cstdio>
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

int N, M;
string S;
vector<int> A;
vector<vector<int>> dp;

bool check(int L, int R) {
	if (R >= N)
		return false;
	assert(L >= 0 && L < N);
	FOR(id, L, R) if (S[id] == '.') return false;

	bool boundary_check = true;
	if (L - 1 >= 0) {
		boundary_check &= S[L - 1] != '#';
	}
	if (R + 1 < N) {
		boundary_check &= S[R + 1] != '#';
	}

	return boundary_check;
}

int go(int i, int j) {
	if (i >= N) {
		return j == M;
	}
	if (j == M) {
		for (int id = i; id < N; id++) {
			if (S[id] == '#')
				return 0;
		}
		return 1;
	}

	int& ans = dp[i][j];
	if (~ans)
		return ans;
	ans = 0;
	// start a group of size = A[j]
	int c1 = 0;

	if (check(i, i + A[j] - 1)) {
		int from = i, to = i + A[j] - 1;

		if (to + 1 < N) {
			assert(S[to + 1] != '#');
		}
		c1 += go(to + 2, j + 1);
	}

	int c2 = 0;
	if (S[i] != '#') {
		c2 = go(i + 1, j);
	}

	return ans = c1 + c2;
}

int solve(string S, vector<int> A) {
	::S = S;
	::A = A;
	N = S.size();
	M = A.size();

	dp = vector<vector<int>>(N, vector<int>(M, -1));

	return go(0, 0);
}

int32_t main() {
	int ans = 0;

	string S, digs;
	while (cin >> S >> digs) {
		vector<int> A;
		int num = 0;
		for (char ch : digs) {
			if (isdigit(ch)) {
				num = num * 10 + (ch - '0');
			} else {
				A.push_back(num);
				num = 0;
			}
		}

		assert(num > 0);
		A.push_back(num);

		S = S + "?" + S + "?" + S + "?" + S + "?" + S;
		vector<int> new_A;
		F0R(iter, 5) {
			for (int x : A) {
				new_A.push_back(x);
			}
		}

		A = new_A;
		int ways = solve(S, A);
		ans += ways;
	}
	cout << ans << endl;
}
