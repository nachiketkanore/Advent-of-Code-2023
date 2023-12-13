/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 13 December 2023 07:58:03 PM IST
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

int solve(const vector<string>& mat) {
	const int N = mat.size();
	const int M = mat[0].size();
	int ans = 0;
	see("new test case");

	FOR(row, 1, N - 1) {
		bool good = true;
		F0R(col, M) {
			int r1 = row - 1, r2 = row;
			while (r1 >= 0 && r2 < N) {
				good &= mat[r1--][col] == mat[r2++][col];
			}
		}
		if (good) {
			see("horizontal line found ", row);
			ans += 100 * row;
		}
	}

	FOR(col, 1, M - 1) {
		bool good = true;
		F0R(row, N) {
			int c1 = col - 1, c2 = col;
			while (c1 >= 0 && c2 < M) {
				good &= mat[row][c1--] == mat[row][c2++];
			}
		}
		if (good) {
			ans += col;
		}
	}
	return ans;
}

int solve_part_one() {
	int answer = 0;

	string line;
	vector<string> curr_grid;
	while (cin >> line) {
		if (line == "$") {
			if (!curr_grid.empty()) {
				answer += solve(curr_grid);
			}
			curr_grid.clear();
		} else {
			curr_grid.push_back(line);
		}
	}
	return answer;
}

int32_t main() {
	freopen("in1", "r", stdin);
	cout << solve_part_one();
}
