#include <bits/stdc++.h>

#define fr first
#define sc second
#define mk make_pair
#define pb push_back

using namespace std;

typedef long long ll;
using P = pair <ll, ll>;

const int N = 1e3 + 5;

P ar[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> ar[i].fr >> ar[i].sc;
	}
	ll cura = ar[1].fr, curb = ar[1].sc;
	for (int i = 2; i <= n; i ++) {
		int a = ar[i].fr, b = ar[i].sc;
		if (cura == a && curb == b) continue;
		if (cura <= a && curb <= b) {
			cura = a;    curb = b;
		} else if (cura <= a && curb >= b) {
			ll cnt = (curb + b - 1) / b;
			cura = cnt * a;
			curb = cnt * b;
		} else if (cura >= a && curb <= b) {
			ll cnt = (cura + a - 1) / a;
			cura = cnt * a;
			curb = cnt * b;
		} else if (cura >= a && curb >= b) {
			ll cnt = (cura + a - 1) / a;
			if (cnt * b < curb) {
				cnt = (curb + b - 1) / b;
				cura = cnt * a;
				curb = cnt * b;
			} else {
				cura = cnt * a;
				curb = cnt * b;
			}
		}
	}
	cout << cura + curb << endl;
	return 0;
}
