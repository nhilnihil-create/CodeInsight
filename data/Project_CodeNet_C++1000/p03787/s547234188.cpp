#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;

using namespace std;
#define N 100010
ll n,m;
int vis[N];
vector<int> v[N];
bool dfs(int x,int bef){
    if(vis[x]==bef)return 0;
    bef=3-bef;
    if(vis[x]==bef)return 1;
    vis[x]=bef;
    bool ok=true;
    for(auto y:v[x]){
	ok&=dfs(y,bef);
    }
    return ok;
}
int main(){
    cin>>n>>m;
    lol(i,m){
	int a,b;cin>>a>>b;a--,b--;
	v[a].push_back(b);
	v[b].push_back(a);
    }
    lol(i,n)vis[i]=0;
    ll x=0,y=0,z=0;
    lol(i,n){
	if(vis[i]==0){
	    if(v[i].size()==0)z++;
	    else{
		if(dfs(i,1))x++;
		else y++;
	    }
	}
    }
    ll ans=2*x*(x+y)+y*y;
    ans+=n*n-(n-z)*(n-z);
    cout<<ans<<endl;
    return 0;
}
