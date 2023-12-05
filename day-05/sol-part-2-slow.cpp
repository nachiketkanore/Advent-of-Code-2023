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
	assert(sz(seeds) % 2 == 0);

	for (int idx = 0; idx < sz(seeds); idx += 2) {

		int start = seeds[idx];
		int total = seeds[idx + 1];

		FOR(seed, start, start + total - 1) {
			int x = seed;
			F0R(mapping_id, 7) {
				for (auto [dest, src, len] : ranges[mapping_id]) {
					if (src <= x && x <= src + len - 1) {
						int diff = x - src;
						x = dest + diff;
						break;
					}
				}
			}
			ans = min(ans, x);
			see(idx, seed);
		}
	}
	cout << ans;

	return 0;
}
