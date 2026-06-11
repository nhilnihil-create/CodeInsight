#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define ull unsigned long long

using namespace std;

LL n;
vector <int> v;
deque <int> q;

int main() {
	scanf ("%lld", &n);
	n++;
	while (n > 1) {
		if (n % 2 == 0) {
			v.pb(0);
			n /= 2;
		}
		else {
			v.pb(1);
			n -= 1;
		}
	}
	printf ("%d\n", 2 * ss(v));
	reverse(all(v));
	rep(i, 1, ss(v))
		printf ("%d ", i);
	int cnt = 0;
	for (auto it : v) {
		if (it == 0) q.push_back(++cnt);
		else q.push_front(++cnt);
	}
	for (auto it : q) printf ("%d ", it);
	
	
    return 0;
}
