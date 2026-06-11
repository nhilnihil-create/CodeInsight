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
  int a, b;
  cin >> a >> b;
  if (a%3 == 0 || b%3 == 0 || (a+b)%3 == 0) cout << "Possible\n";
  else cout << "Impossible\n";
}