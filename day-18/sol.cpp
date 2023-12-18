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

enum direction { right = 0, down = 1, left = 2, up = 3 };
vector<array<int, 4>> vlines;
int ci = 0, cj = 0000;
int min_row = ci, max_row = ci;
int border_length = 0;

int get_dir(char ch) {
	if (ch == 'R')
		return 0;
	if (ch == 'D')
		return 1;
	if (ch == 'L')
		return 2;
	if (ch == 'U')
		return 3;
	return -1;
}

void input() {
	string line;

	// see(ci, cj);

	while (getline(cin, line)) {
		// int dist = stol(line.substr(sz(line) - 7, 5), nullptr, 16);
		// int dir = stoi(line.substr(sz(line) - 2, 1));

		int dist = 0;
		if (isdigit(line[2]) && isdigit(line[3])) {
			dist = (line[2] - '0') * 10 + (line[3] - '0');
		} else if (isdigit(line[2])) {
			dist = line[2] - '0';
		}
		int dir = get_dir(line[0]);
		direction move = static_cast<direction>(dir);
		border_length += dist;

		if (move == direction::left) {
			// hlines.push_back({ ci, cj - dist, ci, cj });
			cj -= dist;
		}
		if (move == direction::right) {
			// hlines.push_back({ ci, cj, ci, cj + dist });
			cj += dist;
		}
		if (move == direction::up) {
			vlines.push_back({ ci - dist, cj, ci, cj });
			ci -= dist;
		}
		if (move == direction::down) {
			vlines.push_back({ ci, cj, ci + dist, cj });
			ci += dist;
		}
		min_row = min(min_row, ci);
		max_row = max(max_row, ci);
	}

	see(ci, cj);
	see(min_row, max_row);
}
int32_t main() {
	// freopen("test", "r", stdin);
	freopen("in1", "r", stdin);
	input();
	int ans = 0;

	FOR(row, min_row, max_row) {
		// get sum of lengths of horizontal lines passing through this row

		vector<int> verticals;
		for (auto [r1, c1, r2, c2] : vlines) {
			assert(c1 == c2);
			assert(r1 < r2);
			if (r1 <= row && row <= r2) {
				verticals.push_back(c1);
			}
		}
		sort(ALL(verticals));
		int row_contrib = 0;

		for (int i = 0; i + 1 < sz(verticals); i += 2) {
			int c1 = verticals[i], c2 = verticals[i + 1];
			row_contrib += c2 - c1 - 1;
		}
		see(row, row_contrib);
		ans += row_contrib;
	}

	see(border_length);
	see(ans);
	ans += border_length;
	see(ans);

	return 0;
}
