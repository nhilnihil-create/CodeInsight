#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
typedef long long LL;
const LL mod = 1e9 + 7;
// head
const int maxn = 2e5 + 5;
int n, a[maxn], f[maxn][27];
LL ans;

int main() {
	cin>>n;
	rep(i, 1, n) { 
	    cin>>a[i];
	    f[i][0] = a[i];
	}
	rep(k, 1, 25)
	    rep(i, 1, n) 
	    	if(i - (1<<(k - 1)) >= 0) f[i][k] = min(f[i][k - 1], f[i - (1<<(k - 1))][k - 1]);
	    	
	rep(i, 1, n) {
		int l = 1, r = i, x, y;
		while(l < r) {
			int mid = (l + r)>>1;
			int mi = 1e9, now = i;
			per(j, 25, 0) 
				if(1<<j <= now - mid + 1)
					mi = min(mi, f[now][j]), now -= 1<<j;
			if(mi == a[i]) r = mid;
			else l = mid + 1;
		}
		x = i - l + 1;
		l = i, r = n;
		while(l < r) {
			int mid = (l + r + 1)>>1;
			int mi = 1e9, now = mid;
			per(j, 25, 0) 
				if(1<<j <= now - i + 1)
					mi = min(mi, f[now][j]), now -= 1<<j;
			if(mi == a[i]) l = mid;
			else r = mid - 1;
		}
		y = l - i + 1;
		ans += (LL) x*y*a[i];
	}
	cout<<ans<<endl;
}