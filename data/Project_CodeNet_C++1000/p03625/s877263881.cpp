#include <bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep_i(i, n) for (int i = 0; i < (n); ++i)
#define rep_ll(i, n) for (long long i = 0; i < (n); ++i)
#define r_rep_i(i, start, end) for (int i = (start); i < (end); ++i)
#define r_rep_ll(i, start, end) for (long long i = (start); i < (end); ++i)
#define debug_vi(v) copy((v).begin(), (v).end(), ostream_iterator<int>(cout, " "));
#define debug_vll(v) copy((v).begin(), (v).end(), ostream_iterator<long long>(cout, " "));
#define debug_vd(v) copy((v).begin(), (v).end(), ostream_iterator<double>(cout, " "));
#define sort_v(v) sort((v).begin(), (v).end()); //昇順
#define d_sort_vi(v) sort((v).begin(), (v).end(), greater<int>()); //降
#define d_sort_vll(v) sort((v).begin(), (v).end(), greater<long long>()); //降
#define d_sort_vd(v) sort((v).begin(), (v).end(), greater<double>()); //昇順
#define say(t) cout << (t) << endl;
#define sum_vi(v) accumulate((v).begin(), (v).end(), 0);
#define sum_vll(v)accumulate((v).begin(), (v).end(), 0LL);

ll gcd(ll a, ll b) { return b?gcd(b, a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a, b)*b;}
const int IINF=(1<<30);
const ll LLINF = 1LL<<60;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n; cin >> n;
  vector<ll> hoge(n);
  rep_i(i, n){
    cin >> hoge[i];
  }
  d_sort_vll(hoge);

  ll m1 = 0;
  ll m2 = 0;
  int i = 0;
  while (i < n){
    if(m1 == 0){
      if(hoge[i] == hoge[i+1]){
        m1 = hoge[i];
        i += 2;
      }else{
        i += 1;
      }
      continue;
    }
    if(m2 == 0){
      if(hoge[i] == hoge[i+1]){
        m2 = hoge[i];
        i += 2;
      }else{
        i += 1;
      }
      continue;
    }
    if(m1 != 0 && m2 != 0){
      break;
    }
  }
  ll ans = m1*m2;
  cout << ans << endl;
}