/**
 *    Author: Nachiket Kanore
 *    Created: Monday 11 December 2023 08:06:08 PM IST
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
	vector<string> mat;
	string line;
	while (cin >> line) {
		mat.push_back(line);
		if (line == string(line.size(), '.')) {
			mat.push_back(line);
		}
	}
	const int n = mat.size();
	const int m = mat[0].size();
	vector<string> final_mat(n);

	F0R(col, m) {
		string col_values;
		F0R(row, n) {
			col_values += mat[row][col];
			final_mat[row] += mat[row][col];
		}
		if (col_values == string(col_values.size(), '.')) {
			F0R(row, n) {
				final_mat[row] += mat[row][col];
			}
		}
	}
	return final_mat;
}

const int MAX = 150;
const int INF = 1e9;
int dist[MAX][MAX];
const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

int32_t main() {
	// freopen("in1", "r", stdin);
	vector<string> A = input();
	see(A.size(), A[0].size());

	const int N = A.size();
	const int M = A[0].size();

	auto inside = [&](
				  int i, int j) { return i >= 0 && i < N && j >= 0 && j < M; };

	auto start_bfs = [&](int si, int sj) -> int {
		F0R(i, N) F0R(j, M) dist[i][j] = INF;
		queue<pair<int, int>> Q;
		Q.push({ si, sj });
		dist[si][sj] = 0;

		while (!Q.empty()) {
			auto [i, j] = Q.front();
			Q.pop();

			F0R(id, 4) {
				int ni = i + dx[id], nj = j + dy[id];
				if (inside(ni, nj) && dist[ni][nj] > dist[i][j] + 1) {
					dist[ni][nj] = dist[i][j] + 1;
					Q.push({ ni, nj });
				}
			}
		}

		int total = 0;
		F0R(i, N) F0R(j, M) if (A[i][j] == '#') total += dist[i][j];
		return total;
	};

	int ans = 0;
	F0R(i, N) F0R(j, M) {
		if (A[i][j] == '#') {
			ans += start_bfs(i, j);
		}
	}
	assert(ans % 2 == 0);
	ans >>= 1;

	cout << ans << '\n';
}
