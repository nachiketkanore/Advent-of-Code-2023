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

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

string digits[9] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	string line;
	while (cin >> line) {
		int first, last;
		bool first_found = false;
		const int N = line.size();

		auto check_digit = [&](int from) {
			for (int j = 0; j < 9; j++) {
				int len = (int)digits[j].size();
				int end_id = from + len - 1;
				if (end_id < N) {
					string value = line.substr(from, len);
					if (value == digits[j]) {
						return j;
					}
				}
			}
			return -1;
		};

		for (int i = 0; i < N; i++) {
			char ch = line[i];
			if (isdigit(ch)) {
				last = ch - '0';
				if (!first_found) {
					first_found = true;
					first = ch - '0';
				}
			}
			int which = check_digit(i);
			if (~which) {

				int d = which + 1;
				last = d;

				if (!first_found) {
					first_found = true;
					first = d;
				}
			}
		}
		int value = first * 10 + last;
		ans += value;
	}
	cout << ans << endl;

	return 0;
}
