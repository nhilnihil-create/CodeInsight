#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include<iostream>
#include<cmath>
#include<math.h>
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
const double PI=M_PI;
signed main(){
    ll n;cin>>n;
    vector<ll>a(n);
    rep(i,n){
        cin>>a[i];
    }
    sort(all(a));
    ll mi=0;
    ll now=0;
    rep(i,n-1){
        now+=a[i];
        if(now*2>=a[i+1])continue;
        else mi=i+1;
    }
    cout<<n-mi<<endl;
}