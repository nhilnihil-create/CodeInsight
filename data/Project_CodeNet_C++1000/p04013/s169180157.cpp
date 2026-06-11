#include<bits/stdc++.h>
using namespace std;
#define maxn 55
#define int long long
int n,m,w,ans,a[maxn],f[maxn][maxn * maxn];
signed main(){
//	freopen("date.in","r",stdin);
//	freopen("date.out","w",stdout);
	f[0][0] = 1;
	scanf("%lld%lld",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
		w += a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j >= 1; j--){
			for(int k = w; k >= a[i]; k--){
				f[j][k] += f[j - 1][k - a[i]];
			}
		}
	}
	for(int i = 1; i <= n; i++){
		ans += f[i][i * m];
	}
	printf("%lld",ans);
	return 0;
}
