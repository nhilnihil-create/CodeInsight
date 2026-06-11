#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
static const int INF = 2000000000;



int main(){
  ll x;
  cin >> x;
  ll ans = (x / 11) * 2;
  ll rest = x % 11;
  if (rest > 0 && rest <= 6) ans++;
  else if (rest > 6) ans += 2;
  cout << ans << endl;
}