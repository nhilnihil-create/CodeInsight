#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define sz(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

int n;
string a, b;

int main() {
	cin >> n >> a >> b;
	int m = 0;
	rep(i, 1, n) 
		if (a.substr(n - i, i) == b.substr(0, i)) m = i;	
	printf ("%d\n", n + n - m);
    return 0;
}

