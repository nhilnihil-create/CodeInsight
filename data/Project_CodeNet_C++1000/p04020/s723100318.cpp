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
    ll ans=0;
    ll n;cin>>n;
    vector<ll>a(n);
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n-1){
        if(a[i]%2==0){
            ans+=a[i]/2;
            a[i]=0;
        }else{
            if(a[i+1]>0){
                ans++;
                a[i]--;
                a[i+1]--;
            }
        }
    }
    rep(i,n){
        ans+=a[i]/2;
    }
    cout<<ans<<endl;
}