#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <sstream>
#include <set>
#include <map>
#define LLMAX 9223372036854775807

using namespace std;
using ll = long long;

int main() {
	ll argN, argL, argT;
	cin >> argN >> argL >> argT;

	vector<ll> argX(argN);
	vector<ll> argW(argN);

	for (ll i = 0; i < argN; ++i) {
		cin >> argX.at(i) >> argW.at(i);
	}

	ll counter = 0;
	for (ll i = 0; i < argN; ++i) {
		if (argW.at(i) == 1) {
			counter -= (argX.at(i) + argT) / argL;
			argX.at(i) = (argX.at(i) + argT) % argL;

		}
		else {
			counter += ((argT - (argX.at(i) + 1)) + argL) / argL;
			argX.at(i) = ((argX.at(i) - argT) % argL + argL) % argL;
		}
	}

	sort(argX.begin(), argX.end());
	vector<ll> res(argN);
	counter = (counter % argN + argN) % argN;
	for (ll i = 0; i < argN; ++i) {
	    res.at((i + counter) % argN) = argX.at(i);
	}
	
	for (ll i = 0; i < argN; ++i) {
		cout << res.at(i) << endl;
	}
}