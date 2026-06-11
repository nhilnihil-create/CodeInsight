# include <bits/stdc++.h>

using namespace std;

const int M = 1e5 + 10;
int n, a[M];

inline int gcd(int a, int b) {
	if(b == 0) return a;
	else return gcd(b, a%b);
}

inline bool go() {
	bool all1 = 1;
	int cnt = 0;
	for (int i=1; i<=n; ++i) {
		all1 &= (a[i] == 1);
		if(a[i] == 1) continue;
		cnt += (a[i]%2 == 0);
	}
	if(all1) return 0;
	if(cnt&1) return 1;
	else {
		if(n - cnt != 1) return 0;
		else {
			for (int i=1; i<=n; ++i) if(a[i] != 1 && (a[i]&1)) --a[i];
			int t = -1;
			for (int i=2; i<=n; ++i) 
				if(a[i] != 1) {
					if(t == -1) t = a[i];
					else t = gcd(t, a[i]);
				}
			for (int i=1; i<=n; ++i) if(a[i] != 1) a[i] /= t;
			return go() ^ 1;
		}
	}
}

int main() {
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> a[i];	
	cout << (go() ? "First" : "Second");
	return 0;
}
			