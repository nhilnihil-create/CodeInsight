#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const double PI = acos(-1);

int main(){
	int n;cin>>n;
    vl t(n),a(n);
    rep(i,n)cin>>t[i];
    rep(i,n)cin>>a[i];
    reverse(been(a));
    if(t[n-1]!=a[n-1]){
        cout<<0<<endl;
        return 0;
    }
    rep(i,n-1){
        if(t[i]>t[i+1]){
            cout<<0<<endl;
            return 0;
        }
        if(a[i]>a[i+1]){
            cout<<0<<endl;
            return 0;
        }
    }
    vl sum(n,INF);
    vector<bool>bt(n,false),at(n,false);
    bt[0]=true;at[0]=true;
    rep(i,n){
        if(i==0)continue;
        if(t[i-1]!=t[i])bt[i]=true;
        if(a[i-1]!=a[i])at[i]=true;
    }
    reverse(been(a));reverse(been(at));
    rep(i,n){
        sum[i]=min(a[i],t[i]);
        if(bt[i]&&sum[i]!=t[i]){
            cout<<0<<endl;
            return 0;
        }
        if(at[i]&&sum[i]!=a[i]){
            cout<<0<<endl;
            return 0;
        }
    }
    
    ll ans =1;
    rep(i,n){
        if(!at[i]&&!bt[i])ans=ans*sum[i]%mod;
    }
    cout<<ans<<endl;;
}