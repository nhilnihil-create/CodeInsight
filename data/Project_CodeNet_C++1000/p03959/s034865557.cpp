#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n+1),b(n+1);
    rep(i,n)cin>>a[i+1];
    rep(i,n)cin>>b[i];
    vector<ll> h(n,inf);
    vector<int> fix(n);
    rep(i,n){
        h[i]=min(h[i],a[i+1]);
        if(a[i]<a[i+1])fix[i]=1;
    }
    rep(i,n){
        if(fix[i]&&b[i]<h[i]){
            cout<<0<<endl;
            return 0;
        }
        if(b[i]>b[i+1]&&b[i]>h[i]){
            cout<<0<<endl;
            return 0;
        }
        h[i]=min(h[i],b[i]);
        if(b[i]>b[i+1])fix[i]=1;
    }
    ll ans=1;
    rep(i,n){
        if(fix[i])continue;
        ans=ans*h[i]%mod;
    }
    cout<<ans<<endl;

    return 0;
}