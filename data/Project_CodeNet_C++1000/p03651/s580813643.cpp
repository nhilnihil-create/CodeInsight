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
ll gcd(ll a,ll b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    else return gcd(b%a,a);
}
signed main(){
    ll n,k;cin>>n>>k;
    vector<ll>a(n);
    ll now=0;
    rep(i,n){
        cin>>a[i];
        now=gcd(now,a[i]);
    }
    bool f=0;
    rep(i,n){
        if(a[i]>=k){
            if((a[i]-k)%now==0)f=1;
        }
    }
    cout<<(f?"POSSIBLE":"IMPOSSIBLE")<<endl;
}