#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 100100;
ll st[MN*4];
int n;
void up(int l, int r, ll val) {
	l += 2*n;r += 2*n;
	for(;l<r;l>>=1,r>>=1) {
		if(l&1) {st[l++] += val;}
		if(r&1) {st[--r] += val;}
	}
}
ll qu(int p) {
	ll res = 0;
	for(p+=2*n;p>0;p>>=1) {
		res += st[p];
	}
	return res;
}
int v[MN];
ll rt[2*MN];
int main() {
	int m;
	scanf("%d %d ",&m,&n);
	memset(st,0,sizeof(st));
	memset(rt,0,sizeof(rt));
	for(int i=0;i<m;i++) {
		scanf("%d ",&v[i]);v[i]--;
	}
	ll tot = 0;
	for(int i=0;i<m-1;i++) {
		int a = v[i],b = v[i+1];
		if(a > b) {b += n;}
		if(a < b) {
			up(a+2,b+1,1);
			up(b+1,b+2,-(b-a-1));
		}
		tot += b-a;
	}
	ll rv = 0;
	for(int i=0;i<2*n;i++) {
		rv += qu(i);
		rt[i] = rv;
	}
	ll ma = 0,mi = 0;
	for(int i=0;i<n;i++) {
		ll sv = rt[i] + rt[i+n];
		if(sv > ma) {ma = sv;mi = i;}
	}
	printf("%lld\n",tot-ma);
}
