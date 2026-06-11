#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
signed main(){
    ll n;cin>>n;
    vector<ll>a(n),b(n);
    rep(i,n){
        cin>>a[i]>>b[i];
    }
    ll cnt=0;
    for(int i=n-1;i>=0;i--){
        a[i]+=cnt;
        if(a[i])cnt+=((a[i]-1)/b[i]+1)*b[i]-a[i];
    }
    cout<<cnt<<endl;
}