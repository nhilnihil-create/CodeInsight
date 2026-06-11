#include<bits/stdc++.h>
#define int long long 
#define ll long long 
using namespace std;
int F[1000009];
long long lazy[4*100005][2];
pair<long long,int> mx(-200000000000000,0);
void push(int v,int tl,int tr) {
	for (int i = 0; i < 2; i++) {
		lazy[v*2][i] += lazy[v][i]; 
		lazy[v*2+1][i] += lazy[v][i]; 
		lazy[v][i]=0;
	}
}
void get(int v,int tl,int tr) {
	if (tl == tr) {
		ll a = lazy[v][0]*tl;
		a += lazy[v][1];
		mx = max(mx,{a,tl});
		return;
	}
	int tm = (tl + tr)/2;
	push(v,tl,tr);
	get(v*2,tl,tm);
	get(v*2+1,tm+1,tr);
}
void add(int v,int tl,int tr,int l,int r,int type,int val) {
	if (r < tl || l > tr || l > r) return;
	if (l <= tl && r >= tr) {
		if (type == 0) {
			lazy[v][0]++;
		}
		else lazy[v][1] += val;
		return;
	}
	int tm = (tl + tr)/2;
	push(v,tl,tr);
	add(v*2,tl,tm,l,r,type,val);
	add(v*2+1,tm+1,tr,l,r,type,val);
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i != 1) {
			if (a[i] > a[i-1]) {
				add(1,1,m,a[i-1] + 2,a[i],0,0);
				add(1,1,m,a[i-1]+2,a[i],1,-a[i-1]-1);
			}
			else {
				add(1,1,m,a[i-1] + 2,m,0,0);
				add(1,1,m,a[i-1] + 2,m,1,-a[i-1]-1);
				add(1,1,m,1,a[i],0,0);
				add(1,1,m,1,a[i],1,m - a[i-1] - 1);
			}
		}
	}
	get(1,1,m);
	int x = mx.second;
	long long ans = 0;
//	x = 2;
	for (int i = 2; i <= n; i++) {
		if (a[i] > a[i-1]) {
			if (x > a[i-1] && x <= a[i]) {
				ans += 1 + a[i] - x;
			}
			else ans += a[i] - a[i-1];
		}
		else {
			if (x > a[i-1]) {
				ans += 1 + (m - x) + a[i];
			}
			else if (x <= a[i]) ans += a[i] - x + 1;
			else ans += m - a[i-1] + a[i];
		}
	}
	cout << ans;
}