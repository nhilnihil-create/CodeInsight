#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long LL;

LL n,ans = 0;
LL a[200005],b[200005];
LL c[200005],d[200005];

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(LL i = 1;i <= n;i ++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1,b + 1 + n);
	for(LL i = 1;i <= n;i ++) a[i] = lower_bound(b + 1,b + 1 + n,a[i]) - b;
	
	for(LL i = 1;i <= n;i ++) if((a[i] & 1) != (i & 1)) ans ++;
	ans >>= 1;
	cout << ans << endl;
	return 0;
}
//