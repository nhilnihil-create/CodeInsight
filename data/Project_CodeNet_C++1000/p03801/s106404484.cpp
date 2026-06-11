#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>
#define fi first
#define se second

const int N = 1e5 + 7;

int n, ans[N];
pii a[N];

bool cmp(pii x, pii y){
	return (x.fi > y.fi || (x.fi == y.fi && x.se < y.se));
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i].fi, a[i].se = i;
	sort(a + 1, a + n + 1, cmp);
	
	
	for(int i = 1, pick = i, cur = a[pick].fi; i <= n; ){
		if(i <= n && a[i].fi == a[i + 1].fi) ++i;
		int ptr = i + 1;
		ans[a[pick].se] += (ptr - 1) * (cur - a[ptr].fi);
		cur = a[ptr].fi;
		pick = (a[pick].se > a[ptr].se ? ptr : pick);
		i = ptr;
	}
	
	for(int i = 1; i <= n; ++i) cout << ans[i] << "\n";
}
