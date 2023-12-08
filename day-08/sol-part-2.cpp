/**
 *    Author: Nachiket Kanore
 *    Created: Friday 08 December 2023 08:51:26 PM IST
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

int N;
string path;
map<string, string> L, R;
vector<string> curr;

void input() {
	cin >> path;
	N = path.size();
	string u, l, r;
	while (cin >> u >> l >> r) {
		L[u] = l;
		R[u] = r;
		if (u.back() == 'A') {
			curr.push_back(u);
		}
	}
}

int lcm(int a, int b) {
	return (a * b) / __gcd(a, b);
}

int32_t main() {
	input();

	int id = 0;
	int ans = 1;
	int path_length = 0;
	for (string start : curr) {
		string C = start;
		int id = 0, len = 0;
		while (C.back() != 'Z') {
			len++;
			if (path[id] == 'L') {
				C = L[C];
			} else if (path[id] == 'R') {
				C = R[C];
			}
			id = (id + 1) % N;
		}
		ans = lcm(ans, len);
	}
	cout << ans;
	return 0;
}
