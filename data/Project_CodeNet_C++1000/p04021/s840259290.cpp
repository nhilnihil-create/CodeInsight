#define rep(i, a, b) for(int i = a; i < (int)(b); i++)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
template<class T> inline void chmax(T &a, const T &b) {if(a < b) a = b;}
template<class T> inline void chmin(T &a, const T &b) {if(a > b) a = b;}
const long long INF = 1LL<<60;

const ll DIV = (ll)1e9+7;
// const ll MAXN = (ll)1e5+10;

int main(void) {
   int N;
   cin>>N;
   map<ll,ll> A;
   rep(i,0,N) {
      ll a;
      cin>>a;
      A.insert(make_pair(a,i));
   }
   ll ans = 0;
   ll cnt = 0;
   for (auto el:A) {
      // cout<<el.second<<" "<<el.first<<" "<<cnt<<endl;
      if ((el.second-cnt)%2 != 0) ans++;
      cnt++;
   }
   cout<<ans/2<<endl;

   return 0;
}

