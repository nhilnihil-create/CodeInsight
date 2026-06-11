#include<bits/stdc++.h>
#define ll long long
#define INF 1000000ll
using namespace std;
signed main(){
  int n,m;
  cin >> n >> m;
  vector<string> a(n);
  vector<string> b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++){
    cin >> b[i];
  }

  for (int i = 0; i+(m-1) < n; i++) {
    for (int j = 0; j+(m-1) < n; j++) {
      bool f = true;
      for (int k = 0; k < m; k++) {
        for (int l = 0; l < m; l++) {
          if (a[i+k][j+l] != b[k][l]) {
            f = false;
          }
        }
      }
      if (f) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
}