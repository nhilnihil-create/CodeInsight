#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define rep(i,s,n) for(int i = s;i<n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
const ll MOD=1000000007,INF=1e18;
 
int N,K;
vint g[2020];
int dist[2020];

void dfs(int now,int par,int cost){
    for(auto e:g[now]){
        if(e==par)continue;
        if(dist[e]!=INF)continue;
        dist[e]=cost;
        dfs(e,now,cost+1);
    }
}

signed main() {
    IOS();
    cin>>N>>K;
    rep(i,0,N-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int ans=INF;
    if(K%2){
        rep(i,0,N){
            for(auto j:g[i]){
                if(i>=j)continue;
                rep(k,0,N){
                    if(k==i||k==j)dist[k]=0;
                    else dist[k]=INF;
                }
                dfs(i,-1,1);
                dfs(j,-1,1);
                int tmp=0;
                rep(k,0,N)if(dist[k]>(K-1)/2)tmp++;
                chmin(ans,tmp);
            }
        }
    }else{
        rep(i,0,N){
            rep(k,0,N){
                if(k==i)dist[k]=0;
                else dist[k]=INF;
            }
            dfs(i,-1,1);
            int tmp=0;
            rep(k,0,N)if(dist[k]>K/2)tmp++;
            chmin(ans,tmp);
        }
    }
    cout<<ans<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}