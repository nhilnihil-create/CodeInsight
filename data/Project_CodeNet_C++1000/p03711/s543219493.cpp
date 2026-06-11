#include <bits/stdc++.h>
using namespace std;
#define ll long long  
template <typename T>
bool PN(T x){ if (x <= 1) return false; if (x == 2) return true; for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false; return true;}

const ll MOD = 1e9+7;

void solve(){
  int x, y; cin >> x >> y;
  int check[13] = {-1, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
  if(check[x] == check[y]) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main()
{
  solve();
  return 0;
}