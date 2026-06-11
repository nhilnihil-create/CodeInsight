#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
typedef long long LL;
const LL mod = 1e9 + 7;
const int N = 3e5 + 5;

int n, k, c, t[N], ans;

int main() {
	cin>>n>>c>>k;
	rep(i, 1, n) 
	    cin>>t[i];
	sort(t + 1, t + n + 1);
	for(int l = 1, r; l <= n; l = r) {
		r = l;
		ans++;
		while(r - l + 1 <= c && t[r] <= t[l] + k) 
			r++;
	}
	printf("%d\n", ans);
}