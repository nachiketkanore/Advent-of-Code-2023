/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 December 2023 11:20:18 AM IST
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

const int MAX = 2000;
int N, M;
bool vis[MAX][MAX];

void input() {
	string line;
	int ci = 1000, cj = 1000;
	vis[ci][cj] = true;
	while (getline(cin, line)) {
		char dir = line[0];
		int move = 0;
		if (isdigit(line[2]) && isdigit(line[3])) {
			move = (line[2] - '0') * 10 + (line[3] - '0');
		} else if (isdigit(line[2])) {
			move = line[2] - '0';
		} else
			assert(false);

		if (dir == 'R') {
			FOR(j, cj, cj + move) {
				vis[ci][j] = true;
			}
			cj += move;
		} else if (dir == 'L') {
			FOR(j, cj - move, cj) {
				vis[ci][j] = true;
			}
			cj -= move;
		} else if (dir == 'U') {
			FOR(i, ci - move, ci) {
				vis[i][cj] = true;
			}
			ci -= move;
		} else if (dir == 'D') {
			FOR(i, ci, ci + move) {
				vis[i][cj] = true;
			}
			ci += move;
		} else
			assert(false);
	}
}

const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { -1, 1, 0, 0 };

int vis_cnt = 0;
void dfs(int i, int j) {
	if (i < 0 || i >= MAX || j < 0 || j >= MAX)
		return;
	if (vis[i][j])
		return;
	vis_cnt++;
	vis[i][j] = true;

	F0R(id, 4) {
		dfs(i + dx[id], j + dy[id]);
	}
}

int32_t main() {
	// freopen("test", "r", stdin);
	input();

	vector<int> counts;
	int vis_loop = 0;
	F0R(i, MAX) F0R(j, MAX) vis_loop += vis[i][j];
	F0R(i, MAX) F0R(j, MAX) if (!vis[i][j]) {
		vis_cnt = 0;
		dfs(i, j);
		counts.push_back(vis_cnt);
	}
	sort(ALL(counts));
	cout << "answer = " << (vis_loop + counts[0]) << endl;

	return 0;
}
