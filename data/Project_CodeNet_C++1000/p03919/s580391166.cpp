#include<iostream>
#include<algorithm>
#include<math.h>
#include<set>
#include<vector>
#include<map>
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<string>
#include<random>
#include<numeric>
#include<string>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
	if (a<b) { return gcd(b, a); }
	else if (a%b) { return gcd(b, a%b); }
	else { return b; }
}
int main() {
	ll h, w;
	cin >> h >> w;
	for (ll i = 0; i < h; i++) {
		for (ll j = 0; j < w; j++) {
				string s;
				cin >> s;
				if (s == "snuke") {
				char c = 'A' + j;
				cout << c << i + 1<< endl;
				return 0;
			}
		}
	}
}