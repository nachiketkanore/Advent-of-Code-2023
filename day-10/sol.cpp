/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 10 December 2023 12:09:28 PM IST
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

vector<string> mat;
int N, M, si, sj;

const string CHARS = "|-LJ7F";
map<char, array<int, 4>> adj;

void init() {
	//		  dx1, dy1, dx2, dy2
	adj['|'] = { -1, 0, +1, 0 };
	adj['-'] = { 0, -1, 0, +1 };
	adj['L'] = { -1, 0, 0, +1 };
	adj['J'] = { -1, 0, 0, -1 };
	adj['7'] = { 0, -1, +1, 0 };
	adj['F'] = { 0, +1, +1, 0 };
}

void input() {
	string line;
	int row = 0;
	while (cin >> line) {
		mat.push_back(line);
		M = line.size();
		F0R(j, M) if (line[j] == 'S') {
			si = row, sj = j;
		}
		row++;
	}
	N = mat.size();
}

vector<vector<int>> get_neighbors(const vector<string>& A, int i, int j) {
	char ch = A[i][j];
	assert(adj.count(ch) > 0);
	vector<vector<int>> neighbors;

	auto [dx1, dy1, dx2, dy2] = adj[ch];
	int ni1 = i + dx1, nj1 = j + dy1;
	int ni2 = i + dx2, nj2 = j + dy2;
	neighbors.push_back({ ni1, nj1 });
	neighbors.push_back({ ni2, nj2 });

	return neighbors;
}

bool inside(int i, int j) {
	return i >= 0 && i < N && j >= 0 && j < M;
}

int solve(const vector<string>& A) {
	vector<vector<int>> dist(N, vector<int>(M, 1e9));
	queue<pair<int, int>> Q;
	Q.push({ si, sj });
	dist[si][sj] = 0;

	while (!Q.empty()) {
		auto [ci, cj] = Q.front();
		Q.pop();

		auto [dx1, dy1, dx2, dy2] = adj[A[ci][cj]];
		int ni1 = ci + dx1, nj1 = cj + dy1;
		int ni2 = ci + dx2, nj2 = cj + dy2;
		if (!inside(ni1, nj1) || !inside(ni2, nj2) || A[ni1][nj1] == '.' || A[ni2][nj2] == '.')
			continue;
		auto c_neighbors = get_neighbors(A, ci, cj);

		auto n1_neighbors = get_neighbors(A, ni1, nj1);
		auto n2_neighbors = get_neighbors(A, ni2, nj2);
		vector<int> curr = { ci, cj };
		// see(curr, c_neighbors, n1_neighbors, n2_neighbors);

		if (count(ALL(n1_neighbors), curr) && count(ALL(n2_neighbors), curr)) {
			if (dist[ni1][nj1] > dist[ci][cj] + 1) {
				dist[ni1][nj1] = dist[ci][cj] + 1;
				Q.push({ ni1, nj1 });
			}
			if (dist[ni2][nj2] > dist[ci][cj] + 1) {
				dist[ni2][nj2] = dist[ci][cj] + 1;
				Q.push({ ni2, nj2 });
			}
		}
	}
	int ans = 0;
	F0R(i, N) F0R(j, M) if (dist[i][j] < 1e9) {
		cout << "X\n"[j == M - 1];
		ans = max(ans, dist[i][j]);
	}
	else {
		cout << ".\n"[j == M - 1];
	}
	return ans;
}

int32_t main() {
	input();
	init();
	int best = 0;
	for (char put : CHARS) {
		auto new_mat = mat;
		new_mat[si][sj] = put;
		best = max(best, solve(new_mat));
	}
	cout << best << '\n';
}
