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

    ll c,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str;
    cin>>n;
    vector<ll> b(n);
    vector<ll> a(n);
    rep(i,n) cin>>a[i]>>b[i];
    for(ll i=n-1;i>=0;i--){
      // cout<<a[i]+sum<<" "<<b[i]<<" "<<(b[i])-(a[i]+sum)%b[i]<<endl;
      if(a[i]!=0&&b[i]!=1&&(a[i]+sum)%b[i]!=0)sum+=abs((b[i])-(a[i]+sum)%b[i]);
    }
    cout<<sum<<endl;
    return 0;
}
