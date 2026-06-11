#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL N = 100005;

LL n,sum = 0,tot,cnt;
LL a[N],b[N];

int main(){
	cin >> n;
	for(LL i = 1;i <= n;i ++) cin >> a[i]; a[0] = a[n];
	for(LL i = 1;i <= n;i ++){
		b[i] = a[i] - a[i - 1];
		sum += a[i];
	}
	if(sum % ((n * (n + 1)) / 2)){ cout << "NO\n"; return 0; }
	tot = sum / ((n * (n + 1)) / 2);
	for(LL i = 1;i <= n;i ++){
		b[i] = b[i] - tot;
		if(b[i] % n || b[i] > 0){ cout << "NO\n"; return 0; }
	}
	cout << "YES\n";
	return 0;
}