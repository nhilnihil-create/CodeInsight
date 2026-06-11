#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
#include <algorithm>
#include <string>


using namespace std;
using ll = long long;
using ull = unsigned long long;


#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a-1;i>=b;i--)

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int n = 0;
	int ha, hb, hc;
	ha = a;
	hb = b;
	hc = c;
	if (a % 2 == 0
		&& b % 2 == 0
		&& c % 2 == 0) {
	}
	else {
		cout << 0 << endl;
		return 0;
	}

	while (true) {
		if (ha % 2 == 1 || hb % 2 == 1 || hc % 2 == 1) {
			cout << n << endl;
			return 0;
		}

		if (ha == hb && hb == hc && ha == hc) {
			cout << -1 << endl;
			return 0;
		}

		int tempa, tempb, tempc;
		tempa = ha;
		tempb = hb;
		tempc = hc;
		ha = (tempb + tempc) / 2;
		hb = (tempa + tempc) / 2;
		hc = (tempa + tempb) / 2;
		n += 1;



	}
	return 0;
}

