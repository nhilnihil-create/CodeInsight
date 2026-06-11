#include<bits/stdc++.h>
#define Abra_Ka_Dabra ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const long long mod = 1e9 + 7;
const double PI = acos(-1);
const double EPS = 1e-9;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	Abra_Ka_Dabra

	string x, y;
	cin >> x >> y;
	if (x[0] == '-') x.erase(x.begin());
	if (y[0] == '-') y.erase(y.begin());
	if (x.size() > y.size()) cout << "GREATER\n";
	else if (x.size() < y.size()) cout << "LESS";
	else {
		for (int i = 0; i < x.size(); i++) {
			if (x[i] > y[i]) {
				cout << "GREATER\n";
				return 0;
			} else if (x[i] < y[i]) {
				cout << "LESS";
				return 0;
			}
		}
		cout << "EQUAL\n";
	}

	return 0;
}
