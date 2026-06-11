#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

bool win(const vector<int> &v) {
	int evens = 0;
	for(auto &each : v) {
		evens += each % 2 == 0;
	}
	if(evens & 1) {
		return true;
	}
	else if((int) v.size() - evens == 1) {
		vector<int> next_v = v;
		int gc = 0;
		for(auto &each : next_v) {
			if(each & 1) {
				if(each == 1) {
					return false;
				}
				each--;
			}
			gc = gcd(gc, each);
		}
		for(auto &each : next_v) {
			each /= gc;
		}
		return !win(next_v);
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	fori(i, 0, n) {
		cin >> v[i];
	}
	
	cout << (win(v) ? "First" : "Second") << '\n';

	return 0;
}

