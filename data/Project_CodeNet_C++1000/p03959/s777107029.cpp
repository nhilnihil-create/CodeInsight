#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int>>
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define MEMSET(a) memset(a,0,sizeof(a))
#define inf (1ll<<60)
#define Yes(f) cout<<(f?"Yes":"No")<<endl
#define yes(f) cout<<(f?"yes":"no")<<endl
#define YES(f) cout<<(f?"YES":"NO")<<endl
#define SORT(v) sort(all(v))
#define RSORT(v) sort(all(v), greater<int>())

using namespace std;

const int mod=1e9+7;

void run();

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
}

signed main(){
    init();
    run();
    return 0;
}

void run(){
    int n;
    cin>>n;
    vi t(n),a(n);
    rep(i,n)cin>>t[i];
    rep(i,n)cin>>a[i];
    vi y(n);
    y[0]=t[0];
    Rep(i,1,n){
        if(t[i]!=t[i-1])y[i]=t[i];
    }
    if(y[n-1]!=0&&y[n-1]!=a[n-1]){
        cout<<0<<endl;
        return;
    }
    y[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        if(a[i]!=a[i+1]){
            if(y[i]!=0&&y[i]!=a[i]||y[i]==0&&a[i]>t[i]){
                cout<<0<<endl;
                return;
            }
            y[i]=a[i];
        }
    }
    int ans=1;
    rep(i,n){
        // cout<<y[i]<<" ";
        if(y[i]==0)ans=ans*min(t[i],a[i])%mod;
    }
    // cout<<endl;
    cout<<ans<<endl;
}