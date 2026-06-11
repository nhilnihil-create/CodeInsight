#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long LL;
const LL N = 400005;

LL n;
LL a[N],b[N];

LL chk(LL x){
	LL ls[2]; ls[0] = ls[1] = n + 1;
	b[0] = 2; b[n << 1] = 2;
	for(LL i = 1;i <= (n << 1) - 1;i ++) b[i] = (a[i] > x);
	for(LL i = n;i <= (n << 1) - 1;i ++){
		if(b[i] == b[i + 1]) ls[b[i]] = min(ls[b[i]],i - n);
	}
	for(LL i = n;i >= 1;i --){
		if(b[i] == b[i - 1]) ls[b[i]] = min(ls[b[i]],n - i);
	}
//	cout << x << ' ' << ls[0] << ' ' << ls[1] << endl;
	if(ls[0] == n + 1 && ls[1] == n + 1) return x == n ? 1 : 0;
	return ls[0] < ls[1];
}

int main(){
	ios::sync_with_stdio(false);
	LL l,r,mid,ans = 1;
	cin >> n;
	for(LL i = 1;i <= (n << 1) - 1;i ++) cin >> a[i];
	l = 1; r = (n << 1) - 1;
	while(l <= r){
		mid = (l + r) >> 1;
		if(chk(mid)){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << '\n';
	return 0;
}