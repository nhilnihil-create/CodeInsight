#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
static const int INF = 2000000000;



int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(ALL(a));
  vector<ll> b;
  ll tmp = a[0];
  int c = 1;
  for (int i = 1; i < n; i++){
    if (a[i] == tmp){
      c++;
      if (c%2 == 0) b.push_back(tmp);
    } else {
      tmp  = a[i];
      c = 1;
    }
  }
  if (b.size() >= 2) {
    ll ans = b[b.size()-1] * b[b.size()- 2];
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
}