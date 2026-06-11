#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using ld = long double;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,a,n) for(ll i=a;i<(ll)(n);i++)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;i--)
#define lb lower_bound
#define ub upper_bound
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 +99);
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T>T mpow(T a, T n) {
   T res = 1;
   for(;n;n>>=1) {
      if (n & 1) res = res * a;
      a = a * a;
   }
   return res;
}

//cin.tie(0);ios::sync_with_stdio(false);



signed main(){
  string s,t;cin>>s>>t;
  vector<ll> sums(siz(s)+1,0),sumt(siz(t)+1,0);
  int q;cin>>q;

  rep(i,0,siz(s)){
    sums[i+1]=sums[i]+(s[i]-'A');
  }

  rep(i,0,siz(t)){
    sumt[i+1]=sumt[i]+(t[i]-'A');
  }

  while(q--){
    ll a,b,c,d;cin>>a>>b>>c>>d;
    a--;b--;c--;d--;
    ll sres=b-a+1+sums[b+1]-sums[a];
    ll tres=d-c+1+sumt[d+1]-sumt[c];
    //cout<<sres<<" "<<tres<<endl;
    if(sres%3 == tres%3)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}