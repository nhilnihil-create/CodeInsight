#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

const int N = 1e5+6;
int n, dist, x[N], right[N], st[20][N];

int jump(int pos, int x){
	for (int i=19; i>=0; i--){
		if ((x>>i)&1) pos = st[i][pos];
	}
	return pos;
}

signed main(){
	cin >> n;
	for (int i=1; i<=n; i++) cin >> x[i];
	cin >> dist;
	for (int i=1; i<=n; i++){
		int l = upper_bound(x+1, x+n+1, x[i]+dist)-x-1;
		st[0][i] = l;
	}
	for (int i=1; i<20; i++){
		for (int j=1; j<=n; j++){
			st[i][j] = st[i-1][st[i-1][j]];
		}
	}
	int q; cin >> q;
	while (q--){
		int u, v; cin >> u >> v;
		if (u>v) swap(u, v);
		int l = 0, r = n;
		while (l!=r){
			int mid = (l+r)>>1;
			if (jump(u, mid)>=v) r = mid;
			else l = mid+1;
		}
		cout << l << endl;
	}
}