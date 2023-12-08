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

void input() {
	cin >> path;
	N = path.size();
	string u, l, r;
	while (cin >> u >> l >> r) {
		L[u] = l;
		R[u] = r;
	}
}

int32_t main() {
	input();

	int id = 0;
	string curr = "AAA";
	int path_length = 0;
	while (curr != "ZZZ") {
		path_length++;
		id %= N;
		if (path[id] == 'L') {
			curr = L[curr];
		} else if (path[id] == 'R') {
			curr = R[curr];
		} else {
			assert(false);
		}
		id++;
	}
	cout << path_length;

	return 0;
}
