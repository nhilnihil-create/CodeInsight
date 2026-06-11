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
typedef vector<pint>vpint;
const ll MOD=998244353,INF=1ll<<60;
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
typedef pair<int,pint>P2;
typedef vector<vint>vvint;

int N,K;
int a[100010],b[100010];

signed main() {
    IOS();
    cin>>N>>K;
    rep(i,0,N){
        cin>>a[i]>>b[i];
    }
    
    int ans=0;
    rep(i,0,N)if((K|a[i])==K)ans+=b[i];
    rrep(i,0,33){
        int tmp=0,sum=0;
        if(K&(1ll<<i)){
            tmp=(K^(1ll<<i));
            rep(j,0,i)tmp|=(1ll<<j);
        }
        rep(j,0,N){
            if((tmp|a[j])==tmp){
                sum+=b[j];
            }
        }
        chmax(ans,sum);
    }
    cout<<ans<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}