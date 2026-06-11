#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=300+10;
ll d[maxn][maxn];
int main(){
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			scanf("%lld",&d[i][j]);
	ll ans=0ll;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			if(d[i][j]!=d[j][i]){
				printf("-1");
				return 0;
			}
	for(ll i=1;i<n;i++)
		for(ll j=i+1;j<=n;j++){
			bool b=0;
			for(ll k=1;k<=n;k++){
				if(k==i || k==j) continue;
				if(d[i][k]+d[k][j]<d[i][j]){
					printf("-1");
					return 0;
				}
				else if(d[i][k]+d[k][j]==d[i][j]){
					b=1;
				}
			}
			if(!b) ans+=d[i][j];
		}
	printf("%lld",ans);
	return 0;
}