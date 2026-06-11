#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
static const int INF = 2000000000;


int main(){
  ll n, m;
  cin >> n >> m;
  ll ans;
  if (2*n >= m){
    ans = m / 2;
  } else {
    ans = n;
    m -= 2 * n;
    ans += m / 4;
  }
  cout << ans << endl;
}