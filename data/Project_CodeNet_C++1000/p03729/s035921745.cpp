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
  string a, b, c;
  cin >> a >> b >> c;
  if (a[a.size()-1] == b[0] && b[b.size()-1] == c[0]) cout << "YES\n";
  else cout << "NO\n";
}