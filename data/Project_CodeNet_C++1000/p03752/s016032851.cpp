//q014.cpp
//Sun Aug  9 11:16:16 2020

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

	ll ans = LLINF;
	rep(i,1<<(n-1)){
		ll height = a[0];
		ll cost = 0;
		if (bitset<32>(i).count()!=k-1){
			continue;
		}
		rep(j,n-1){
			if (i>>j&1){
				cost+=max(height-a[j+1]+1,0LL);
				height=max(a[j+1],height+1);
			}else {
				height = max(height,a[j+1]);
			}
		}
		ans = min(ans,cost);
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}