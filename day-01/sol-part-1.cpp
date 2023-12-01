/**
 *    Author: Nachiket Kanore
 *    Created: Friday 01 December 2023 11:43:11 PM IST
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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	string line;
	while (cin >> line) {
		char first, last;
		bool first_found = false;
		for (char ch : line) {
			if (isdigit(ch)) {
				last = ch;
				if (!first_found) {
					first_found = true;
					first = ch;
				}
			}
		}
		int value = (first - '0') * 10 + (last - '0');
		ans += value;
	}
	cout << ans << endl;

	return 0;
}
