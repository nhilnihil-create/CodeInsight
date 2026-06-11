#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>
#include<time.h>

#define DIV 998244353
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
	
	vector<bool> dpw(F/100 + 1);
	dpw[0] = true;
	for (int k = 0; k < F / 100; k++) {
		if (dpw[k]) {
			if (k + A <= F / 100) {
				dpw[k + A] = true;

			}
			if (k + B <= F / 100) {
				dpw[k + B] = true;

			}

		}
	}

	vector<bool> dps(F + 1);
	dps[0] = true;
	for (int k = 0; k < F ; k++) {
		if (dps[k]) {
			if (k + C <= F) {
				dps[k + C] = true;

			}
			if (k + D <= F) {
				dps[k + D] = true;

			}

		}
	}

	int sw = 0, s = 0;
	for (int i = 0; i <= F / 100; i++) {
		if (!dpw[i]) continue;
		
		for (int j = 0; j <= F; j++) {
			if (!dps[j]) continue;
			if (100 * i + j <= F && j <= i * E) {
				if (s * (100 * i + j) <= sw * j) {
					sw = 100 * i + j, s = j;
				}
			}
			else break;
		}


	}

	cout << sw << " " << s << endl;
}
