#include <bits/stdc++.h>
//#include<iostream>
using namespace std;
#define int long long

#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
typedef pair<pint,int> P1;
typedef pair<int,pint> P2;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007,INF=1e18;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int n,m;

vint graph[100010];
bool visit[100010];

vint path,path2;

void dfs(int t){
    visit[t]=true;
    path.pb(t);
    for(auto e:graph[t]){
        if(visit[e]==false){
            dfs(e);
            return ;
        }
    }
}



signed main(){
    cin.tie(0);
	ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    
    dfs(1);
    swap(path,path2);
    dfs(1);
    
    cout<<path.size()+path2.size()-1<<endl;
    rrep(i,1,path2.size())cout<<path2[i]<<" ";
    for(auto e:path)cout<<e<<" ";
    cout<<endl;
    
    
    
    
    
    return 0;
}