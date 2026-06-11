#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pip pair<int,pii>
#define F first
#define S second
#define pb push_back
#define INF 1e18
#define MOD 1000000007
#define N 1000005
#define BB(V) V[V.size()-2]
#define ex(V) return printf(V),0
using namespace std;
int a[305][305];
int chk[305][305];
vector<pip>v;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",a[i]+j);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]>a[i][k]+a[k][j])ex("-1");
				if(a[i][j]==a[i][k]+a[k][j]&&i!=k&&j!=k){
					chk[i][j]=1;
				}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(!chk[i][j])ans+=a[i][j];
		}
	}
	printf("%lld",ans);
}