#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const int mod = 1000000007;
const int inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<int,P>PP;
vector<int>G[2005];
int A[2005],B[2005];
int dis[2005][2005];

void dfs(int now,int par,int top,int K,int &ans){
	for(int e:G[now]){
		if(e==par)continue;
		dis[top][e]=dis[top][now]+1;
		if(dis[top][e]<=K)ans++;
		dfs(e,now,top,K,ans);
		}
	}

signed main(){
	int n,k;cin>>n>>k;
	rep(i,n-1){
		int a,b;cin>>a>>b;
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
		A[i]=a;B[i]=b;
		}
		
	int ans=inf;
	if(k&1){
		rep(i,n-1){
			int res=2;
			int d=0;
			dfs(A[i],B[i],A[i],k/2,d);
			res+=d;d=0;
			dfs(B[i],A[i],B[i],k/2,d);
			res+=d;
			ans=min(ans,n-res);
			}
		}
	else{
		rep(i,n){
			int res=0;
			int d=1;
			dfs(i,-1,i,k/2,d);
			res+=d;
			ans=min(ans,n-res);
			}
		}	
	cout<<ans<<endl;	
}
