#include <bits/stdc++.h>
 
#define all(x) (x).begin(), (x).end()
#define li long long
#define itn int
 
using namespace std;
 
inline int nxt(){
	int n;
	scanf("%d", &n);
	return n;
}

bool solve(vector<int> a) {
	int n = a.size();
	if (n % 2 == 0) {
		int res = 0;
		for (int x : a) {
			res = (res ^ x) & 1;
		}
		return res;
	}

	int s = 0;
	for (int x : a) {
		s += x % 2;
	}
	if (s > 1 || *min_element(all(a)) == 1) {
		return (s % 2 != n % 2);
	} else {
		if (s % 2 != n % 2) {
			return 1;
		}
		int g = 0;
		for (int& x : a) {
			x -= x % 2;
			g = __gcd(g, x);
		}
		for (int& x : a) {
			x /= g;
		}
		return !solve(a);
	}
}

int main(){

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	cout << (solve(a) ? "First" : "Second") << "\n";

	return 0;
}