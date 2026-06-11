#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }


int main() {
  int n,p;
  cin>>n>>p;
   vin a(n);
  rep(i,n) cin>>a[i];
  ////
  int iti=0,zero=0;
  rep(i,n){
    a[i]%=2;
    if(a[i]==1) iti++;
    else zero++;
  }
  if(iti>0)
  cout<<ll(pow(2,n-1))<<endl;
  else if(p==0) cout<<ll(pow(2,n))<<endl;
  else cout<<0<<endl;
}







