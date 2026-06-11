#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;
  
int main() {
  int N;
  cin >> N;
  string s1,s2;
  cin >> s1;
  cin >> s2;
  ll ans;
  auto isTate = [&](int i) {
    return s1[i] == s2[i];
  };
  bool isT = false;
  
  rep(i,N) {
    if(i == 0) {
      if(isTate(0)) {
        ans = 3;
        isT = true;
      } else {
        ans = 6;
        i++;
      }
      continue;
    }
    if(isTate(i)) {
      if(isT) {
        ans *= 2;
      }
      isT = true;
    } else {
      if(isT) {
        ans *= 2;
      } else {
        ans *= 3;
      }
      isT = false;
      i++;
    }
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}