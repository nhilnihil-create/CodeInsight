#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll a[2020];
ll b[2020][2020];
const ll INF = 1e18;
int main()
{
	int n;
	ll x;
	scanf("%d%lld",&n,&x);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < n;j++){
			if(j == 0) b[j][i] = a[i];
			else if(i-j>0) b[j][i] = min(a[i-j],b[j-1][i]);
			else b[j][i] = min(a[n-(j-i)],b[j-1][i]);
		}
	}
	ll ans = INF;
	for(int k = 0;k < n;k++){
		ll res = 0;
		for(int i = 1;i <= n;i++){
			res += b[k][i];
		}
		ans = min(ans,res + k*x);
	}
	cout<<ans<<endl;
}