#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
typedef pair <int, int> PII;
#define int long long
#define all(x) (x.begin(),  x.end())
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
	char c = getchar();
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
const int N = 200010;
int a[N], n, m, cp[N], xp[N];
signed main() {
	n = qread(); m = qread();
	repn(i, n) a[i] = qread();
	int ans = 0, raw = 0;
	repn(i, n - 1) {
	    int t = a[i + 1], s = a[i];
	    if (t < s) t += m;    // we are overflowing the top
	    // we are doing this reversedly so we won't need to deal with negative
	    // numbers (the linear function is originally t - x + 1, and the coeff of x
	    // is negative)
	    raw += t - s;
	    if (s + 1 < t) {
	        // increase 1 to all x-s within the range [s + 1, t]
	        // decrease (s + 1) to all c-s within the range [s + 1, t]
	        // note that it's REVERSED to the f(s, t, x) function
	        xp[s + 1 + 1]++; cp[s + 1 + 1] -= s + 1;
	        xp[t + 1]--; cp[t + 1] += s + 1; 
	    }
	}
	// work the prefix sum
	repn(i, m << 1) {
	    xp[i] += xp[i - 1];
	    cp[i] += cp[i - 1];
	}
//	repn(i, m << 1) {
//	    cerr << i << ": " << xp[i] << ' ' << cp[i] << endl;
//	}
	// get the answer
	repn(i, m) {
	    int tmp = xp[i] * i + xp[i + m] * (i + m) + cp[i] + cp[i + m];
	    ans = max(ans, tmp);
	}
	cout << raw - ans << endl;
	return 0;
}
