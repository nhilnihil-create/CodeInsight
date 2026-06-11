#include<bits/stdc++.h>
#include<iostream>
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
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    ll ans=0;
    rep(i,n){
        if(a[i]==i+1){
            ans++;
            i++;
        }
    }
    cout<<ans<<endl;
}