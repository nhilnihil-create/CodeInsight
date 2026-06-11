#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int INF = 1e9+1;

int main(){
  int n, L;
  cin >> n >> L;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int l = -1, r = -1;
  for (int i = 0; i < n-1; i++) {
    if (a[i] + a[i + 1] >= L) {
      l = i;
      r = i + 1;
      break;
    }
  }

  if (l == -1) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  for (int i = 0; i < l; i++) {
    cout << i + 1 << endl;
  }
  for (int i = n-2; i >= l; i--) {
    cout << i + 1 << endl;
  }

  return 0;
} 