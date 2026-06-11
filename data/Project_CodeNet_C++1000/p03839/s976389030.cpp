#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
const int MOD = 1000000007;
 
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,k; cin >> n >> k ;
  vector<ll> a(n);
  ll psum = 0;
  rep(i,n){
      cin >> a[i];
      if(a[i]>0){
          psum += a[i];
      }
  }
  vector<ll> sa(n+1);
  vector<ll> psa(n+1);
  sa[0] = 0;
  psa[0] = 0;
  rep(i,n){
      sa[i+1] = sa[i] + a[i];
      psa[i+1] = psa[i];
      if(a[i]>0){
          psa[i+1] += a[i];
      }
  }
  ll ans = 0;
  rep(i,n-k+1){
      ll tmp = psa[i] - psa[0] +  psa[n] - psa[i+k];
      if(sa[i+k] - sa[i]>0){
          tmp += sa[i+k] -sa[i];
      }
      ans = max(ans,tmp);
  }
  rep(i,n+1){
      cerr << sa[i] << " " ;
  }
  cerr << endl;
  rep(i,n+1){
      cerr << psa[i] << " " ;
  }
  cout << ans << endl;

}