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

pair<int, int> intersection(int l1, int r1, int l2, int r2) {
	if (r1 < l2 || r2 < l1)
		return { -1, -1 };
	return { max(l1, l2), min(r1, r2) };
}
int32_t main() {
	input();

	int ans = 1e18;
	assert(sz(seeds) % 2 == 0);

	for (int idx = 0; idx < sz(seeds); idx += 2) {

		int start = seeds[idx];
		int total = seeds[idx + 1];
		int L = start, R = start + total - 1;
		vector<pair<int, int>> x_ranges = { { L, R } };

		F0R(mapping_id, 7) {
			vector<pair<int, int>> x_ranges_new, intersections;

			for (auto [L, R] : x_ranges) {
				vector<pair<int, int>> intersections;

				for (auto [dest, src, len] : ranges[mapping_id]) {
					int l = src, r = src + len - 1;
					auto [from, to] = intersection(L, R, l, r);
					if (~from) {
						// 1] for the overlapping part: mapping happens
						int LL = dest + (from - src);
						int RR = dest + (to - src);
						// see(mapping_id, L, R, l, r, LL, RR);
						x_ranges_new.push_back({ LL, RR });
						intersections.push_back({ from, to });
					}
				}
				// 2] for the non-overlapping part: x values remain same
				// [L, R] overlap [l, r] is [from, to]
				// rest of the parts are: [L, from-1] and [to+1, R]
				// add non-interesected points
				sort(ALL(intersections));
				int curr = L;
				for (auto [x, y] : intersections) {
					if (curr < x) {
						x_ranges_new.push_back({ curr, x - 1 });
					}
					curr = y + 1;
				}
				if (curr <= R) {
					x_ranges_new.push_back({ curr, R });
				}
			}
			x_ranges = x_ranges_new;
		}
		sort(ALL(x_ranges));
		ans = min(ans, x_ranges[0].first);
	}
	cout << ans;

	return 0;
}
