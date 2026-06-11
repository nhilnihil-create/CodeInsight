#include <bits/stdc++.h>
using namespace std;
#define ll long long  
template <typename T>
bool PN(T x){ if (x <= 1) return false; if (x == 2) return true; for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false; return true;}

const ll MOD = 1e9+7;

void solve(){
  int n, m; cin >> n >> m;
  char picture[n][m];
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> picture[i][j];
    }
  }

  for(int i = 0; i < m+2; ++i) cout << "#";
  cout << endl;
  for(int i = 0; i < n; ++i){
    cout << "#";
    for(int j = 0; j < m; ++j) cout << picture[i][j];
    cout << "#" << endl;
  }
  for(int i = 0; i < m+2; ++i) cout << "#";
  cout << endl;
  
}

int main()
{
  solve();
  return 0;
}