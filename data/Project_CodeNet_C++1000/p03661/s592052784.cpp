#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int MAXN = 1000005;
const int mod = 998244353;

int n;
lint a[MAXN];

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		int x; scanf("%d",&x);
		a[i] = a[i-1] + x;
	}
	lint ret = 1e18;
	for(int i=1; i<n; i++){
		lint x = a[i];
		lint y = a[n] - a[i];
		ret = min(ret, abs(x - y));
	}
	cout << ret << endl;
}
