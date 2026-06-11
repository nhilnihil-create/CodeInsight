#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

LL ll[400005],rr[400005];
LL stk[400005],tp = 0;
LL n,a[400005],tot = 0;

int main(){
	cin >> n;
	for(LL i = 1;i <= n;i ++) cin >> a[i];
	for(LL i = 1;i <= n;i ++){
		ll[i] = 0;
		rr[i] = n + 1;
	}
	
	tp = 0;
	for(LL i = 1;i <= n;i ++){
		while(tp && a[stk[tp]] > a[i]){
			rr[stk[tp]] = i;
			tp --;
		}
		stk[++ tp] = i;
	}
	
	tp = 0;
	for(LL i = n;i >= 1;i --){
		while(tp && a[stk[tp]] > a[i]){
			ll[stk[tp]] = i;
			tp --;
		}
		stk[++ tp] = i;
	}
	
	for(LL i = 1;i <= n;i ++) tot += (rr[i] - i) * (i - ll[i]) * a[i];
	cout << tot << endl;
	return 0;
}
//