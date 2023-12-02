/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 02 December 2023 10:53:12 AM IST
 **/
#include "bits/stdc++.h"
#include <string>
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

vector<string> get_words(string line) {
	string cur;
	vector<string> words;
	for (char ch : line) {
		if (ch == ' ') {
			words.push_back(cur);
			cur.clear();
		} else {
			cur += ch;
		}
	}
	if (!cur.empty()) {
		words.push_back(cur);
	}
	return words;
}

string remove_last(string S) {
	S.pop_back();
	return S;
}

const int MAXR = 12;
const int MAXG = 13;
const int MAXB = 14;

int32_t main() {

	int ans = 0;
	string line;
	while (getline(cin, line))
		if (!line.empty()) {
			vector<string> words = get_words(line);
			int id = stoi(remove_last(words[1]));

			bool ok = true;
			map<string, int> counts;
			for (int i = 2; i + 1 < (int)words.size(); i += 2) {
				int cnt = stoi(words[i]);
				string color = remove_last(words[i + 1]);
				counts[color] += cnt;

				if (words[i + 1].back() == ';') {

					ok &= counts["red"] <= MAXR && counts["green"] <= MAXG &&
					counts["blue"] <= MAXB;

					counts.clear();
				} else if (words[i + 1].back() == ',') {

				} else {
					assert(false);
				}
			}

			if (ok) {
				see(id);
				ans += id;
			}
		}
	cout << ans;
	return 0;
}
