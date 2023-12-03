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

	auto get_neighbors = [&](int i, int j) {
		vector<pair<int, int>> neighbors;
		F0R(idx, 8) {
			int ni = i + dx[idx];
			int nj = j + dy[idx];
			if (!(0 <= ni && ni < N && 0 <= nj && nj < M))
				continue;
			neighbors.push_back(make_pair(ni, nj));
		}
		return neighbors;
	};

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

	vector<vector<pair<int, int>>> allnums;
	vector<pair<int, int>> stars;

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
				allnums.push_back(positions);
				j = id - 1;
			} else if (mat[i][j] == '*') {
				stars.push_back(make_pair(i, j));
			}
		}
	}

	auto get_number = [&](int id) {
		int value = 0;
		for (auto [ni, nj] : allnums[id]) {
			char digit = mat[ni][nj];
			assert(isdigit(digit));
			value = (value * 10) + (digit - '0');
		}
		return value;
	};

	for (auto [si, sj] : stars) {
		set<int> num_ids;
		for (auto [nsi, nsj] : get_neighbors(si, sj)) {
			F0R(i, sz(allnums)) {
				const auto& num_pos = allnums[i];
				if (count(ALL(num_pos), make_pair(nsi, nsj)) > 0) {
					num_ids.insert(i);
				}
			}
		}
		if (sz(num_ids) == 2) {
			int prod = 1;
			for (int id : num_ids) {
				prod *= get_number(id);
			}
			ans += prod;
		}
	}

	cout << ans << '\n';

	return 0;
}
