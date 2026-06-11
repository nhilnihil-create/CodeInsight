#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
static const int INF = 2000000000;


int main(){
  int w, a, b;
  cin >> w >> a >> b;
  if (a > b) swap(a, b);
  a += w;
  int ans = b - a;
  if (ans < 0) ans = 0;
  cout << ans << endl;
} 