/**
 *    Author: Nachiket Kanore
 *    Created: Monday 11 December 2023 08:06:08 PM IST
 **/
#include "bits/stdc++.h"
#include <deque>
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

const int MAX_NODES = 150 * 150;
bool erow[150], ecol[150];
int n, m;

vector<string> input() {
	vector<string> mat;
	string line;
	int row_id = 0;
	while (cin >> line) {
		mat.push_back(line);
		if (line == string(line.size(), '.')) {
			erow[row_id] = true;
		}
		row_id += 1;
	}
	n = mat.size();
	m = mat[0].size();

	F0R(col, m) {
		string col_values;
		F0R(row, n) {
			col_values += mat[row][col];
		}
		if (col_values == string(col_values.size(), '.')) {
			ecol[col] = true;
		}
	}
	return mat;
}
int32_t main() {
	vector<string> A = input();
	for (int multiply : { 2, 10, 100, 1000'000 }) {
		vector<pair<int, int>> hashes;
		F0R(i, n) F0R(j, m) {
			if (A[i][j] == '#') {
				hashes.push_back({ i, j });
			}
		}

		// new coordinates of hashes
		for (auto& [i, j] : hashes) {
			int ROW = i, COL = j;
			F0R(row, ROW) if (erow[row]) i += multiply - 1;
			F0R(col, COL) if (ecol[col]) j += multiply - 1;
		}

		int ans = 0;
		// since there are no obstacles in the grid
		// all possible 4 direction movements are allowed
		// hence min distance between two hashes is simply = manhattan distance between them
		for (auto [i, j] : hashes) {
			for (auto [ni, nj] : hashes) {
				ans += abs(ni - i) + abs(nj - j);
			}
		}
		assert(ans % 2 == 0);
		ans /= 2;

		cout << "Multiply = " << multiply << ", answer = " << ans << endl;
	}
}
