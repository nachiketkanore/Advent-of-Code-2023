/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 06 December 2023 07:13:14 PM IST
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

vector<int> T, D;

int32_t main() {

	int N;
	cin >> N;
	T.resize(N);
	D.resize(N);
	for (int& x : T)
		cin >> x;
	for (int& x : D)
		cin >> x;

	int answer = 1;
	F0R(id, N) {
		int t = T[id];
		int ways = 0;
		F0R(hold, t + 1) {
			int t_remain = t - hold;
			int speed = hold;
			int x = speed * t_remain;
			if (x > D[id]) {
				++ways;
			}
		}
		answer *= ways;
	}
	cout << answer;

	return 0;
}
