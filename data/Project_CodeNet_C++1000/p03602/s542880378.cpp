#include <bits/stdc++.h>

#define int long long

using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
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

int n;
int d[333][333];
int a[333][333];

void warshall_floyd(int n){
  rep(i,0,n)rep(j,0,n)rep(k,0,n){
    if(d[j][k]>d[j][i]+d[i][k])d[j][k]=d[j][i]+d[i][k];
  }
}


signed main(){
    cin>>n;
    rep(i,0,n){
        rep(j,0,n){
            cin>>d[i][j];
            a[i][j]=d[i][j];
        }
    }
    int ans=0;
    
    warshall_floyd(n);
    
    rep(i,0,n){
        rep(j,i+1,n){
            bool can=false;
            if(a[i][j]>d[i][j]){
                cout<<"-1"<<endl;
                return 0;
            }
            rep(k,0,n){
                if(k==i||k==j)continue;
                if(d[i][k]+d[k][j]==d[i][j])can=true;
            }
            if(!can)ans+=d[i][j];
            //cout<<d[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
    
    
    
    
    return 0;
}