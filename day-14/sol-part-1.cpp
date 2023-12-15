/**
 *    Author: Nachiket Kanore
 *    Created: Friday 15 December 2023 11:11:50 PM IST
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

int N, M;
vector<string> mat;

void input() {
	string line;
	while (cin >> line) {
		mat.push_back(line);
	}
	N = mat.size();
	M = mat[0].size();
}

int contribution(string S) {
	int c0 = 0, c1 = 0;
	string T;
	for (char ch : S) {
		if (ch == '#') {
			while (c0--)
				T += 'O';
			while (c1--)
				T += '.';
			T += '#';
			c0 = c1 = 0;
		} else {
			c0 += (ch == 'O');
			c1 += (ch == '.');
		}
	}
	while (c0--)
		T += 'O';
	while (c1--)
		T += '.';

	int ans = 0;

	assert(sz(T) == N);
	F0R(i, N) if (T[i] == 'O') ans += N - i;

	return ans;
}

int32_t main() {
	input();
	int answer(0);
	F0R(col, M) {
		string column;
		F0R(row, N) {
			column += mat[row][col];
		}
		answer += contribution(column);
	}
	cout << answer;
}
