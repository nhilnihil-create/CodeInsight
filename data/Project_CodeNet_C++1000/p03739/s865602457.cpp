#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

int main(){
  int n; cin >> n;
  vector<ll> a(n+1), sum(n+1);
  a[0] = 0, sum[0] = 0;
  REP(i, 1, n) cin >> a[i];

  ll cnt1 = 0;
  REP(i, 1, n){
    sum[i] = sum[i-1] + a[i];
    if(i%2 == 1 && sum[i] >= 0){
      cnt1 += sum[i] - (-1);
      sum[i] = -1;
    }
    else if(i%2 == 0 && sum[i] <= 0){
      cnt1 += 1 - sum[i];
      sum[i] = 1;
    }
  }

  ll cnt2 = 0;
  REP(i, 1, n){
    sum[i] = sum[i-1] + a[i];
    if(i%2 == 0 && sum[i] >= 0){
      cnt2 += sum[i] - (-1);
      sum[i] = -1;
    }
    else if(i%2 == 1 && sum[i] <= 0){
      cnt2 += 1 - sum[i];
      sum[i] = 1;
    }
  }

  cout << min(cnt1, cnt2) << endl;

  return 0;
}
