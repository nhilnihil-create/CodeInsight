#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 1e5+7;

int n, a, b;
ll h[maxn];
bool check(ll x){
	ll sum=0;
	ll sub=a-b;
	for(int i=1; i<=n; ++i){
		if(x*b<h[i]){
			ll tmp=h[i]-x*b;
			sum += (tmp-1)/sub+1;
		}
	}
	return sum<=x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> a >> b;
	for(int i=1; i<=n; ++i){
		cin >> h[i];
	}
	sort(h+1, h+1+n);
	ll l=1, r=1e9+7;
	while(l<r){
		ll mid = l+r>>1;
		if(check(mid)){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	cout << r;
}