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
  int n;
  cin >> n;

  int cnt1 = 0;
  int cnt2 = 0;
  int cnt4 = 0;
  rep(i, n){
    int a; cin >> a;
    if(a%4 == 0) cnt4++;
    else if(a%2 == 0) cnt2++;
  }

  if(cnt2 == 0){
    cout << (cnt4*2 +1 >= n ? "Yes" : "No") << endl;
    return 0;
  }

  cout << (cnt4*2 >= n-cnt2 ? "Yes" : "No") << endl;

  return 0;
}
