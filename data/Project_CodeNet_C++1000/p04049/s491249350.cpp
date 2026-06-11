#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
template<class T>void chmax(T &a,T b){if(a<b)a=b;}
template<class T>void chmin(T &a,T b){if(a>b)a=b;}
constexpr int INF=1000000000;
int n,k,a[2010],b[2010],ans=INF;
vector<int>v[2010];
int d[2010];
bool memo[2010];
void dfs(int x){
	for(int i:v[x]){
		if(d[i]==INF){
			d[i]=d[x]+1;
			dfs(i);
		}
	}
}
signed main(){
	cin>>n>>k;
	rep(i,n-1){
		cin>>a[i]>>b[i];
		a[i]--,b[i]--;
		v[a[i]].pb(b[i]);
		v[b[i]].pb(a[i]);
	}
	if(k%2){
		rep(i,n-1){
			fill(memo,memo+n,true);
			fill(d,d+n,INF);d[a[i]]=0;
			dfs(a[i]);
			rep(j,n)if(d[j]<=k/2)memo[j]=false;
			fill(d,d+n,INF);d[b[i]]=0;
			dfs(b[i]);
			rep(j,n)if(d[j]<=k/2)memo[j]=false;
			int cnt=0;
			rep(j,n)if(memo[j])cnt++;
			chmin(ans,cnt);
		}
		cout<<ans<<endl;
	}
	else{
		rep(i,n){
			fill(d,d+n,INF);
			d[i]=0;
			dfs(i);
			int cnt=0;
			rep(j,n)if(d[j]>k/2)cnt++;
			chmin(ans,cnt);
		}
		cout<<ans<<endl;
	}
    return 0;
}
