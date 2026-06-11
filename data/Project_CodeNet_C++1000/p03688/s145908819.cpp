#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n;cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    sort(all(a));
    bool f=0;
    if(a[0]==a[n-1]){
        if(a[0]==n-1)f=1;
        if(a[0]<=n/2)f=1;
    }
    else if(a[n-1]-a[0]==1){
        ll cnt=0;
        rep(i,n){
            if(a[i]==a[0])cnt++;
        }
        if(a[n-1]-cnt<=(n-cnt)/2&&a[n-1]-cnt>0)f=1;
    }
    cout<<(f?"Yes":"No")<<endl;
}