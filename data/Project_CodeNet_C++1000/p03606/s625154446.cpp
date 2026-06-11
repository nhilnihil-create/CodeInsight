#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
static const int INF = 2000000000;

int main(){
  int n;
  cin >> n;
  int ans = 0;
  rep(i, n){
    int l, r;
    cin >> l >> r;
    ans += r - l + 1;
  }
  cout << ans << endl;
}
