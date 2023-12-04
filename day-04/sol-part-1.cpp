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
int32_t main() {
	int ans = 0;
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
		int points = 0;
		for (int y : second) {
			if (count(first.begin(), first.end(), y) > 0) {
				if (points == 0)
					points = 1;
				else
					points <<= 1;
			}
		}
		ans += points;
	}
	cout << ans;

	return 0;
}

