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

int solve_individual_vertical(const vector<string> mat) {
	const int N = mat.size();
	const int M = mat[0].size();

	// vertical line
	FOR(col, 1, M - 1) {
		bool good = true;
		F0R(row, N) {
			int c1 = col - 1, c2 = col;
			while (c1 >= 0 && c2 < M) {
				good &= mat[row][c1--] == mat[row][c2++];
			}
		}
		if (good) {
			return col;
		}
	}
	return -1;
}

int solve_individual_horizontal(const vector<string> mat) {
	const int N = mat.size();
	const int M = mat[0].size();

	// horizontal line
	FOR(row, 1, N - 1) {
		bool good = true;
		F0R(col, M) {
			int r1 = row - 1, r2 = row;
			while (r1 >= 0 && r2 < N) {
				good &= mat[r1--][col] == mat[r2++][col];
			}
		}
		if (good) {
			return row;
		}
	}
	return -1;
}

int solve(vector<string> mat) {
	const int N = mat.size();
	const int M = mat[0].size();
	int sum = 0;
	int original_horizontal_line = solve_individual_horizontal(mat);
	int original_vertical_line = solve_individual_vertical(mat);
	// see(original_horizontal_line);

	F0R(i, N) {
		F0R(j, M) {
			mat[i][j] = (mat[i][j] == '#' ? '.' : '#');
			int new_horizontal_line = solve_individual_horizontal(mat);
			mat[i][j] = (mat[i][j] == '#' ? '.' : '#');
			if (new_horizontal_line != -1 && new_horizontal_line != original_horizontal_line) {
				sum += 100 * new_horizontal_line;
			}
		}
	}
	F0R(i, N) {
		F0R(j, M) {
			mat[i][j] = (mat[i][j] == '#' ? '.' : '#');
			int new_vertical_line = solve_individual_vertical(mat);
			mat[i][j] = (mat[i][j] == '#' ? '.' : '#');
			if (new_vertical_line != -1 && new_vertical_line != original_vertical_line) {
				sum += new_vertical_line;
				// return sum;
			}
		}
	}

	// see(original_vertical_line, original_horizontal_line, "NOT FOUND");
	// for (string row : mat) {
	// 	cout << row << endl;
	// }
	// see("......");

	return sum;
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
	// freopen("in1", "r", stdin);
	// freopen("test", "r", stdin);
	cout << solve_part_one();
}
