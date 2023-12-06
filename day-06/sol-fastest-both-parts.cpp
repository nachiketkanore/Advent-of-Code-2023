/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 06 December 2023 07:13:14 PM IST
 **/
#include "bits/stdc++.h"
#include <math.h>
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

	// t = 1 million
	// hold = [0,t]
	// x = hold * (t - hold)
	// x = hold * t - hold * hold
	// t = constant
	// hold = variable (x)
	// f(x) = k*x - x * x
	// y = -x*x + k*x
	// find ranges of values of x (hold) in [0, t]
	// for which y > d
	// -x*x + k*x > d
	// x*x - k*x + d < 0
	//

	int answer = 1;
	F0R(id, N) { // N = 1
		int t = T[id], d = D[id];
		int a = 1, b = -t, c = d;
		// axx + bx + c = 0
		// x*x - k*x + d = 0
		// root1 = (-b - sqrt(bb - 4ac)) / 2a
		// root2 = (-b + sqrt(bb - 4ac)) / 2a

		double first = 1. * (-b - sqrtl(b * b - 4 * a * c)) / 2. * a;
		double second = 1. * (-b + sqrtl(b * b - 4 * a * c)) / 2. * a;

		int L = (int)first + 1;
		int R = (int)second;

		int ways = (R - L + 1);
		answer *= ways;

		// cout << setprecision(10) << first << ' ' << second << '\n';
	}
	cout << answer;

	return 0;
}
