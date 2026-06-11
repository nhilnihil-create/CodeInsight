#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n)repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
typedef pair<int,int> P;
typedef pair<int, P> PP;
#define all(v) v.begin(),v.end()
#define fi first
#define se second
const int inf = 1e9;
int mod = 1e9+7;

int bitn = 1, bit[200002];
int L[300002], R[300002];
void add(int l, int r){
	while(l <= bitn){
		bit[l]++;
		l += l&-l;
	}
	r++;
	while(r <= bitn){
		bit[r]--;
		r += r&-r;
	}
}
int get(int x){
	int res = 0;
	while(x > 0){
		res += bit[x];
		x -= x&-x;
	}
	return res;
}

vector<PP> v;
signed main(){
	int n, m;
	scanf("%lld%lld", &n, &m);
	rep(i,n)scanf("%lld%lld", &L[i], &R[i]);
	while(bitn < m)bitn *= 2;
	rep(i,n)v.push_back(PP(R[i]-L[i], P(L[i], R[i])));
	sort(all(v));
	
	int s = n, cnt = 0, ans = 0;
	rrep(i,m){
		while(cnt < n && i > v[cnt].fi){
			add(v[cnt].se.fi, v[cnt].se.se);
			cnt++;s--;
		}
		int sum = 0;
		rrep(j,m){
			if(i*j > m)break;
			sum += get(i*j);
		}
		printf("%lld\n", sum+s);
	}
	return 0;
}