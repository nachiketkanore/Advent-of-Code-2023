#include <bits/stdc++.h>
#define int int64_t
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

vector<string> input() {
	vector<string> in;
	string line;
	while (getline(cin, line)) {
		in.push_back(line);
	}
	return in;
}

vector<string> get_words(string line) {
	string cur;
	vector<string> words;
	for (char ch : line) {
		if (ch == ' ') {
			if (!cur.empty()) {
				words.push_back(cur);
				cur.clear();
			}
		} else {
			cur += ch;
		}
	}
	if (!cur.empty()) {
		words.push_back(cur);
	}
	return words;
}
const int MAX = 1e5;
int counts[MAX];

int32_t main() {
	int ans = 0;
	int line_id = 1;

	for (string line : input()) {
		vector<string> words = get_words(line);
		vector<int> first, second;
		int id = 2;
		while (id < (int)words.size() && words[id] != "|") {
			first.push_back(stoi(words[id++]));
		}
		assert(words[id] == "|");
		id++;
		while (id < (int)words.size()) {
			second.push_back(stoi(words[id++]));
		}
		int pairs = 0;
		for (int y : second) {
			if (count(first.begin(), first.end(), y) > 0) {
				++pairs;
			}
		}
		int self_count = counts[line_id] + 1;
		int L = line_id + 1, R = line_id + pairs;
		for (int id = L; id <= R; id++) {
			counts[id] += self_count;
		}
		ans += self_count;
		line_id++;
	}
	cout << ans;

	return 0;
}

