/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 21 December 2023 04:49:28 PM IST
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

int N, M, si, sj;
vector<string> mat;

void input() {
	string line;
	while (cin >> line) {
		mat.push_back(line);
	}
	N = mat.size();
	M = mat[0].size();
	F0R(i, N) F0R(j, M) if (mat[i][j] == 'S') si = i, sj = j;
}

const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

bool ok(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return false;
	if (mat[i][j] == '#')
		return false;
	return true;
}

int dfs(set<pair<int, int>> curr, int rem) {
	if (rem == 0) {
		return sz(curr);
	} else {
		set<pair<int, int>> nxt;
		for (auto [i, j] : curr) {
			F0R(id, 4) {
				auto [ni, nj] = pair<int, int>{ i + dx[id], j + dy[id] };
				if (ok(ni, nj)) {
					nxt.insert({ ni, nj });
				}
			}
		}
		return dfs(nxt, rem - 1);
	}
}

int32_t main() {
	freopen("test", "r", stdin);
	input();
	// cout << dfs({ { si, sj } }, 6) << endl;
	// part one answer:
	cout << dfs({ { si, sj } }, 64) << endl;
}
