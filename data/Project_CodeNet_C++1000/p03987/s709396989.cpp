#include <bits/stdc++.h>
using namespace std;
#define ALL(A) (A).begin(),(A).end()
#define ll long long
const ll mod = 1e9+7;
const ll INF = 2*1e18;
const int inf = 1e9+7;
int sz = 2e5+5;
vector<ll> bit(sz+1);

int lowbit(int x){
	return x&-x;
}
void add(int x,int w){
	for(int i=x;i<=sz;i += lowbit(i)){
		bit[i] += w;
	}
}
ll sum(int x){
	ll ret = 0;
	for(int i=x;i>0;i-=lowbit(i)){
		ret += bit[i];
	}
	return ret;
}
int search_small(int index){
	ll x = sum(index);
	ll ok = -1;
	ll ng = index;
	while(abs(ok-ng)>1){
		int mid = (ok+ng)/2;
		if(sum(mid)<x)ok = mid;
		else ng = mid;
	}
	return ok;
}
int search_big(int index){
	ll ok = sz;
	ll ng = index;
	while(abs(ok-ng)>1){
		int mid = (ok+ng)/2;
		if(sum(mid)>sum(index))ok = mid;
		else ng = mid;
	}
	return ok;
}
int main(void){
	int N;
	cin >> N ;
	vector<ll> pos(N+1);
	for(int i=1;i<=N;i++){
		int a;
		cin >> a;
		pos[a] = i;
	}
	ll ans = 0;
	for(int i=1;i<=N;i++){
		int nowpos = pos[i];
		int cases = 0;
		int s1 = search_small(nowpos);
		int b1 = search_big(nowpos);
		b1 = min(b1,N+1);
		//cout << "nowpos = " << nowpos;
		//cout << " s1 = " << s1  << " b1 = " << b1 << endl;
		ans += (ll)i * (nowpos - s1 - 1) * (b1 - nowpos);
		add(nowpos,1);
	}
	cout << ans << endl;
}