/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 16 December 2023 03:32:23 PM IST
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
bool visited[500][500];

enum direction { left = 0, right = 1, up = 2, down = 3 };

void input() {
	string line;
	while (cin >> line)
		mat.push_back(line);
	N = mat.size();
	M = mat[0].size();
}

set<array<int, 3>> cache;

void dfs(int i, int j, direction dir) {
	if (i < 0 || i >= N || j < 0 || j >= M)
		return;

	visited[i][j] = true;

	if (cache.count({ i, j, dir }))
		return;

	cache.insert({ i, j, dir });

	if (dir == direction::right) {
		if (mat[i][j] == '.') {
			dfs(i, j + 1, dir);
		} else if (mat[i][j] == '|') {
			dfs(i - 1, j, direction::up);
			dfs(i + 1, j, direction::down);
		} else if (mat[i][j] == '-') {
			dfs(i, j + 1, dir);
		} else if (mat[i][j] == '/') {
			dfs(i - 1, j, direction::up);
		} else if (mat[i][j] == '\\') {
			dfs(i + 1, j, direction::down);
		}
	}
	if (dir == direction::left) {
		if (mat[i][j] == '.') {
			dfs(i, j - 1, dir);
		} else if (mat[i][j] == '|') {
			dfs(i - 1, j, direction::up);
			dfs(i + 1, j, direction::down);
		} else if (mat[i][j] == '-') {
			dfs(i, j - 1, dir);
		} else if (mat[i][j] == '/') {
			dfs(i + 1, j, direction::down);
		} else if (mat[i][j] == '\\') {
			dfs(i - 1, j, direction::up);
		}
	}
	if (dir == direction::up) {
		if (mat[i][j] == '.') {
			dfs(i - 1, j, dir);
		} else if (mat[i][j] == '|') {
			dfs(i - 1, j, dir);
		} else if (mat[i][j] == '-') {
			dfs(i, j - 1, direction::left);
			dfs(i, j + 1, direction::right);
		} else if (mat[i][j] == '/') {
			dfs(i, j + 1, direction::right);
		} else if (mat[i][j] == '\\') {
			dfs(i, j - 1, direction::left);
		}
	}
	if (dir == direction::down) {
		if (mat[i][j] == '.') {
			dfs(i + 1, j, dir);
		} else if (mat[i][j] == '|') {
			dfs(i + 1, j, dir);
		} else if (mat[i][j] == '-') {
			dfs(i, j - 1, direction::left);
			dfs(i, j + 1, direction::right);
		} else if (mat[i][j] == '/') {
			dfs(i, j - 1, direction::left);
		} else if (mat[i][j] == '\\') {
			dfs(i, j + 1, direction::right);
		}
	}
}

int32_t main() {
	input();
	dfs(0, 0, direction::right);
	int answer = 0;
	F0R(i, N) F0R(j, M) answer += visited[i][j];

	cout << answer << '\n';
}
