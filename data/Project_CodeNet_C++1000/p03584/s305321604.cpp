#include <bits/stdc++.h>
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
typedef pair<pint,pint>PP;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007;
const ll INF=1e18;
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};

int N,K;
int a[100010],b[100010];

int f(int n){
    int sum=0;
    rep(i,0,N){
        if((n&a[i])==a[i]){
            sum+=b[i];
        }
    }
    return sum;
}

signed main(){
    cin.tie(0);
	ios::sync_with_stdio(false);
    cin>>N>>K;
    rep(i,0,N){
        cin>>a[i]>>b[i];
    }
    
    int ans=f(K);
    
    rep(i,0,30){
        if((K>>i)&1ll){
            int j=(K^(1ll<<i));
            j|=(1ll<<i)-1;
            ans=max(ans,f(j));
        }
    }
    
    cout<<ans<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}