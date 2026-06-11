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
    ll n,m;cin>>n>>m;
    vector<ll>cnt(n+1);
    rep(i,m){
        ll a,b;cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
    }
    bool f=1;
    REP(i,1,n+1){
        if(cnt[i]%2)f=0;
    }
    cout<<(f?"YES":"NO")<<endl;
}