/**
 *    Author: Nachiket Kanore
 *    Created: Friday 08 December 2023 12:49:11 AM IST
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

vector<char> cards = { 'A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2' };
vector<vector<int>> types = {
	{ 5 },
	{ 1, 4 },
	{ 2, 3 },
	{ 1, 1, 3 },
	{ 1, 2, 2 },
	{ 1, 1, 1, 2 },
	{ 1, 1, 1, 1, 1 },
};
vector<pair<string, int>> A;

void input() {
	string hand;
	int bid_value;
	while (cin >> hand >> bid_value)
		A.push_back(make_pair(hand, bid_value));
}

int card_strength(char ch) {
	F0R(i, sz(cards)) {
		if (cards[i] == ch) {
			return sz(cards) - i;
		}
	}
	assert(false);
	return -1;
}

int get_type(string S) {
	map<char, int> freq;
	for (char ch : S) {
		freq[ch]++;
	}
	vector<int> F;
	for (auto [k, v] : freq) {
		F.push_back(v);
	}
	sort(ALL(F));
	F0R(type_id, sz(types)) {
		if (F == types[type_id]) {
			return type_id;
		}
	}

	assert(false);
	return -1;
}

bool better(const string& one, const string& two) {
	// one					two
	// lower rank           higher rank
	int type_one = get_type(one);
	int type_two = get_type(two);

	if (type_one < type_two) {
		return true;
	} else if (type_one > type_two) {
		return false;
	}
	F0R(i, sz(one)) {
		int c_one = card_strength(one[i]);
		int c_two = card_strength(two[i]);
		if (c_one > c_two) {
			return true;
		} else if (c_one < c_two) {
			return false;
		}
	}
	// assert(false);
	return false;
}

int32_t main() {

	input();
	sort(A.begin(), A.end(), [&](pair<string, int> one, pair<string, int> two) {
		return better(one.first, two.first);
	});

	reverse(ALL(A));
	int ans = 0;
	F0R(i, sz(A)) {
		ans += (i + 1) * A[i].second;
	}
	cout << ans;

	return 0;
}
