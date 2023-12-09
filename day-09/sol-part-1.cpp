/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 09 December 2023 12:13:46 PM IST
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

vector<vector<int>> rows;

void input() {
	string line;
	while (getline(cin, line)) {
		int num = 0;
		bool neg = false;
		vector<int> row;
		for (char ch : line) {
			if (ch == ' ') {
				row.push_back(neg ? -num : +num);
				num = 0;
				neg = false;
			} else if (isdigit(ch)) {
				num = num * 10 + (ch - '0');
			} else if (ch == '-') {
				neg = true;
			}
		}
		row.push_back(neg ? -num : +num);
		rows.push_back(row);
	}
}

bool check_zeros(const vector<int>& row) {
	bool ok = true;
	for (int x : row) {
		ok &= x == 0;
	}
	return ok;
}

int solve(vector<int> row) {
	vector<vector<int>> diffs = { row };
	do {
		vector<int> diff;
		FOR(i, 1, sz(diffs.back()) - 1) {
			diff.push_back(diffs.back()[i] - diffs.back()[i - 1]);
		}
		diffs.push_back(diff);
	} while (!check_zeros(diffs.back()));
	for (int i = sz(diffs) - 1; i >= 0; --i) {
		if (i == sz(diffs) - 1) {
			diffs[i].push_back(0);
		} else {
			int add = diffs[i].back() + diffs[i + 1].back();
			diffs[i].push_back(add);
		}
	}
	return diffs[0].back();
}

int32_t main() {
	input();
	int ans = 0;
	for (auto row : rows) {
		ans += solve(row);
	}
	cout << ans;
}
