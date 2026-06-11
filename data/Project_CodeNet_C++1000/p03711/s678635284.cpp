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
  int x, y;
  cin >> x >>y;
  
  auto f = [&](int c){
    if (c==2) return 1;
    else if (c==4 || c==6 || c==9 || c==11) return 2;
    else return 3;
  };

  int a = f(x);
  int b = f(y);

  if (a == b) cout << "Yes\n";
  else cout << "No\n";
}