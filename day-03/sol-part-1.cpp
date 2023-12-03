/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 03 December 2023 02:02:42 PM IST
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

vector<string> input() {
	vector<string> in;
	string line;
	while (cin >> line) {
		in.push_back(line);
	}
	return in;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> mat = input();

	int ans = 0;
	const int N = mat.size();
	const int M = mat[0].size();

	const int dx[] = { 0, 0, -1, -1, 1, 1, 1, -1 };
	const int dy[] = { 1, -1, -1, 1, -1, 1, 0, 0 };

	auto check_part_number = [&](vector<pair<int, int>> positions) -> bool {
		for (auto [i, j] : positions) {
			F0R(idx, 8) {
				int ni = i + dx[idx];
				int nj = j + dy[idx];
				if (!(0 <= ni && ni < N && 0 <= nj && nj < M))
					continue;
				char ch = mat[ni][nj];
				if (isdigit(ch) || ch == '.')
					continue;
				return true;
			}
		}
		return false;
	};

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (isdigit(mat[i][j])) {
				vector<pair<int, int>> positions;
				int number = 0;
				int id = j;
				while (id < M && isdigit(mat[i][id])) {
					number = number * 10 + (mat[i][id] - '0');
					positions.push_back(make_pair(i, id));
					id++;
				}
				if (check_part_number(positions)) {
					ans += number;
				}
				j = id - 1;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
