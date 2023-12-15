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
char result[500][500];

void input() {
	string line;
	while (cin >> line) {
		mat.push_back(line);
	}
	N = mat.size();
	M = mat[0].size();
}

int get_up(int row, int col, int cnt = 0) {
	if (row == -1 || mat[row][col] == '#') {
		assert(cnt > 0);
		return row + cnt;
	}
	return get_up(row - 1, col, cnt + (mat[row][col] == 'O'));
}

int get_down(int row, int col, int cnt = 0) {
	if (row == N || mat[row][col] == '#') {
		assert(cnt > 0);
		return row - cnt;
	}
	return get_down(row + 1, col, cnt + (mat[row][col] == 'O'));
}

int get_left(int row, int col, int cnt = 0) {
	if (col == -1 || mat[row][col] == '#') {
		assert(cnt > 0);
		return col + cnt;
	}
	return get_left(row, col - 1, cnt + (mat[row][col] == 'O'));
}

int get_right(int row, int col, int cnt = 0) {
	if (col == M || mat[row][col] == '#') {
		assert(cnt > 0);
		return col - cnt;
	}
	return get_right(row, col + 1, cnt + (mat[row][col] == 'O'));
}

int32_t main() {
	freopen("in1", "r", stdin);
	input();
	const int ITER = 1;
	// const int ITER = 1e9;

	auto process = [&](int ci, int cj) -> pair<int, int> {
		F0R(_, ITER) {
			// up direction - row changes
			ci = get_up(ci, cj);
			// left direction - col changes
			cj = get_left(ci, cj);
			// down direction - row changes
			ci = get_down(ci, cj);
			// right direction - col changes
			cj = get_right(ci, cj);
		}
		return make_pair(ci, cj);
	};

	F0R(i, N) F0R(j, M) result[i][j] = '.';

	F0R(i, N) {
		F0R(j, M) {
			if (mat[i][j] == 'O') {
				// see(i, j);
				// see(get_up(i, j));
				// see(get_left(i, j));
				// see(get_down(i, j));
				// see(get_right(i, j));
				auto [ci, cj] = process(i, j);
				// see(i, j, ci, cj);
				result[ci][cj] = 'O';
			}
		}
	}

	F0R(i, N) F0R(j, M) cout << result[i][j] << " \n"[j == M - 1];
}
