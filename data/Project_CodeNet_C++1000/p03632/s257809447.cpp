#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
static const int INF = 2000000000;


int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = min(b, d) - max(a, c);
  if (ans < 0) ans = 0;
  cout << ans << endl;
} 