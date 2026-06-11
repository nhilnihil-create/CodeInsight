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
  int x=0, y=0, z=0;
  rep(i, n) {
    int a;
    cin >> a;
    if (a % 2) x++;
    else {
      if (a % 4) y++;
      else z++;
    }
  }

  if (y > 0) x++;
  if (x - 1 <= z) cout << "Yes\n";
  else cout << "No\n";
}