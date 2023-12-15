/**
 *    Author: Nachiket Kanore
 *    Created: Friday 15 December 2023 11:55:41 PM IST
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

vector<pair<string, int>> A[256];

int get_hash(const string& A) {
	int hash = 0;
	for (char ch : A) {
		hash = (hash + int(ch)) * 17;
		hash %= 256;
	}
	return hash;
}

void remove_operation(string type) {
	int hsh = get_hash(type);
	int del_id = -1;
	F0R(i, sz(A[hsh])) {
		if (A[hsh][i].first == type) {
			del_id = i;
			break;
		}
	}
	if (~del_id) {
		A[hsh].erase(A[hsh].begin() + del_id);
	}
}
void add_operation(string type, int value) {
	int hsh = get_hash(type);
	F0R(i, sz(A[hsh])) {
		if (A[hsh][i].first == type) {
			A[hsh][i].second = value;
			return;
		}
	}
	A[hsh].push_back(make_pair(type, value));
}

void solve(string query) {
	if (query.back() == '-') {
		remove_operation(query.substr(0, sz(query) - 1));
	} else {
		string type = query.substr(0, sz(query) - 2);
		string num;
		num += query.back();
		int value = stoll(num);
		add_operation(type, value);
	}
}

int32_t main() {
	string line;
	cin >> line;
	string curr;
	for (char ch : line) {
		if (ch == ',') {
			solve(curr);
			curr.clear();
		} else {
			curr += ch;
		}
	}

	solve(curr);

	int ans = 0;
	F0R(box_id, 256) {
		F0R(id, sz(A[box_id])) {
			ans += (box_id + 1) * (A[box_id][id].second) * (id + 1);
		}
	}

	cout << ans;
}
