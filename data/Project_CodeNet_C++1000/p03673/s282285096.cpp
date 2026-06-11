// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1001001001
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str;
    cin>>n;
    vector<ll> v(n);
    rep(i,n){
      cin>>v[i];
    }
    deque<ll> ans;
    if(n%2){
      rep(i,n){
        if(i%2) ans.push_back(v[i]);
        else ans.push_front(v[i]);
      }
    }else{
      rep(i,n){
        if(i%2) ans.push_front(v[i]);
        else ans.push_back(v[i]);
      }
    }
    rep(i,n) cout<<ans[i]<<" ";
    return 0;
}
