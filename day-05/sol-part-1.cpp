/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 05 December 2023 06:47:02 PM IST
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

vector<int> seeds;
vector<array<int, 3>> ranges[7];

void input() {
	int cnt;
	cin >> cnt;
	while (cnt--) {
		int seed;
		cin >> seed;
		seeds.push_back(seed);
	}

	F0R(id, 7) {
		int cnt;
		cin >> cnt;
		while (cnt--) {
			int dest, src, len;
			cin >> dest >> src >> len;
			ranges[id].push_back({ dest, src, len });
		}
	}
}

int32_t main() {
	input();

	int ans = 1e18;
	for (int seed : seeds) {
		int x = seed;
		F0R(mapping_id, 7) {
			for (auto [dest, src, len] : ranges[mapping_id]) {
				// src -> dest
				// src+1 -> dest+1
				// ...
				// src+len-1 -> dest+len-1
				// if mapping is possible, then x belongs to [src, src+len-1]
				if (src <= x && x <= src + len - 1) {
					int diff = x - src;
					x = dest + diff;
					break;
				}
			}
		}
		// see("final = ", x);
		ans = min(ans, x);
	}
	cout << ans;

	return 0;
}
