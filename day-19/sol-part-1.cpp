/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 19 December 2023 11:03:53 AM IST
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

struct query {
	int x, m, a, s;
	int rating;
	query(int x, int m, int a, int s)
	: x(x), m(m), a(a), s(s), rating(x + m + a + s) {
	}
};

struct condition {
	enum check { smaller, larger, failsafe } chk;
	char variable;
	int limit;
	string next;
	condition(string next) : chk(check::failsafe), next(next) {
	}
	condition(char value, check op, int limit, string next)
	: variable(value), chk(op), limit(limit), next(next) {
	}

	int get_variable_substitution(query Q) {
		if (this->variable == 'x') {
			return Q.x;
		}
		if (this->variable == 'm') {
			return Q.m;
		}
		if (this->variable == 'a') {
			return Q.a;
		}
		if (this->variable == 's') {
			return Q.s;
		}
		// assert(false);
		return -1;
	}

	string test(query Q) {
		int lhs = get_variable_substitution(Q);
		int rhs = limit;
		if (chk == check::smaller) {
			return lhs < rhs ? next : "";
		}
		if (chk == check::larger) {
			return lhs > rhs ? next : "";
		}
		if (chk == check::failsafe) {
			return next;
		}
		assert(false);
		return "";
	}
};

struct flow {
	string name;
	vector<condition> checks;
	flow(string name) : name(name) {
	}
	void add_check(char value, char op, int limit, string next) {
		if (op == '<') {
			checks.push_back(condition(value, condition::check::smaller, limit, next));
		} else if (op == '>') {
			checks.push_back(condition(value, condition::check::larger, limit, next));
		} else if (op == '=') {
			checks.push_back(condition(next));
		} else {
			assert(false);
		}
	}
};

vector<flow> workflows;
vector<query> queries;

vector<string> split(const string& s, const char delimiter) {
	vector<string> result;
	string curr;
	for (char ch : s) {
		if (ch == delimiter) {
			result.push_back(curr);
			curr.clear();
		} else {
			curr += ch;
		}
	}
	result.push_back(curr);

	return result;
}

void input() {
	string line;
	while (cin >> line) {
		if (line[0] == '{') {
			int x(-1), m(-1), a(-1), s(-1);
			for (auto q : split(line.substr(1, sz(line) - 2), ',')) {
				vector<string> qsplit = split(q, '=');
				int value = stoll(qsplit[1]);
				if (qsplit[0] == "x") {
					x = value;
				} else if (qsplit[0] == "m") {
					m = value;
				} else if (qsplit[0] == "a") {
					a = value;
				} else if (qsplit[0] == "s") {
					s = value;
				} else {
					assert(false);
				}
			}

			assert(~x && ~m && ~a && ~s);
			queries.push_back(query(x, m, a, s));
		} else {
			string name;
			int id = 0;
			while (line[id] != '{')
				name += line[id++];
			flow new_flow = flow(name);
			vector<string> splits = split(line.substr(id + 1, sz(line) - id - 2), ',');

			for (const string s : splits) {
				if (1 < sz(s) && (s[1] == '<' || s[1] == '>')) {
					char value = s[0];
					char op = s[1];
					int limit = 0;
					int id = 2;
					while (isdigit(s[id])) {
						limit *= 10;
						limit += (s[id] - '0');
						id++;
					}
					string next = s.substr(id + 1);
					new_flow.add_check(value, op, limit, next);
				} else {
					new_flow.add_check('x', '=', 'x', s);
				}
			}

			workflows.push_back(new_flow);
		}
	}
}

flow get_flow(string flow_name) {
	for (flow f : workflows) {
		if (f.name == flow_name) {
			return f;
		}
	}
	assert(false);
	return workflows[0];
}

int32_t main() {
	// freopen("in1", "r", stdin);
	// freopen("test", "r", stdin);
	input();

	// see(sz(workflows), sz(queries));
	int answer = 0;

	for (query Q : queries) {
		string wf_name = "in";
		// see("start - ", wf_name);
		while (true) {
			flow curr_wf = get_flow(wf_name);
			for (condition cnd : curr_wf.checks) {
				string new_wf_name = cnd.test(Q);
				if (!new_wf_name.empty()) {
					wf_name = new_wf_name;
					break;
				}
			}
			// see(wf_name);
			if (wf_name == "A" || wf_name == "R") {
				break;
			}
		}
		if (wf_name == "A") {
			answer += Q.rating;
		}
	}

	cout << answer << endl;

	return 0;
}
