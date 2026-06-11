#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

LL a[1005],b[1005],cna = 0,cnb = 0,tot = 1;
LL n,c[1005],cnc = 0;

int main(){
	ios::sync_with_stdio(false);
	cin >> n; n ++;
	while(n){
		c[++ cnc] = n & 1;
		n >>= 1;
	}
	
	b[++ cnb] = 1;
	for(LL i = cnc - 1;i >= 1;i --){
		if(c[i]) a[++ cna] = ++ tot;
		if(i > 1) b[++ cnb] = ++ tot;
	}
	
	cout << tot + 100 << endl;
	for(LL i = cna;i >= 1;i --) cout << a[i] << ' ';
	for(LL i = 1;i <= cnb;i ++) cout << b[i] << ' ';
	for(LL i = 1;i <= 100;i ++) cout << i << (i == 100 ? '\n' : ' ');
	return 0;
}
// 太难了