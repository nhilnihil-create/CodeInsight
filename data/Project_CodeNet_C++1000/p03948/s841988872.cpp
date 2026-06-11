#include <bits/stdc++.h>
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
static const ll maxLL = (ll)1 << 62;
const int mod=1000000007,INF=1001001001;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};


//#define int ll

int n,t,x=0,mina,cnt=1;
int a[100010];

signed main(){
    cin>>n>>t;
    rep(i,0,n){
        cin>>a[i];
    }
    mina=a[0];
    
    rep(i,1,n){
        if(mina<a[i]){
            if(x==a[i]-mina)cnt++;
            x=max(x,a[i]-mina);
        }
        mina=min(mina,a[i]);
    }
    
    cout<<cnt<<endl;
    return 0;
}