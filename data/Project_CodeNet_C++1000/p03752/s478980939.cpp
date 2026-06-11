//q014.cpp
//Wed Sep 23 23:02:45 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <bitset>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n,k;
	cin >> n >> k;

	ll a[n];
	rep(i,n) cin >> a[i];

	ll ans = 1e12;
	rep(i,1<<n){
		ll tmp = 0;
		int z = bitset<32>(i).count();
		if (z<k)continue;
		ll cur = 0;
		rep(j,n){
			if (i>>j & 1){
				tmp += max(cur-a[j]+1,0LL);
				cur = max(cur+1,a[j]);
			}else {
				cur = max(cur,a[j]);
			}
		}
		ans = min(ans,tmp);
	}


	cout << ans << endl;
//	printf("%.4f\n",ans);
}