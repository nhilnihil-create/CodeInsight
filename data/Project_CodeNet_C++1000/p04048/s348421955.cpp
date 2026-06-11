#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> l_l;
typedef pair<int,int> i_i;
const ll MOD=1e9+7;
const int INF=1<<30;

int main(){
  ll N,X;
  cin >> N >> X;
  ll ans=N;
  ll a=N-X;
  ll b=X;
  while(a%b){
    ans+=(a/b*2)*b;
    ll A=a,B=b;
    a=B;
    b=A%B;
  }
  ans+=(a/b*2)*b-b;
  cout << ans << endl;
}