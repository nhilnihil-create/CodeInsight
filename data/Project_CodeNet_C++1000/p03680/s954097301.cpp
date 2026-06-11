#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  vector<int> b(n);
  rep(i, n) cin >> b[i];
  int nx = b[0] - 1;
  int c = 1;
  while(true){
    if(nx == 1) {
      cout << c << endl;
      return 0;
    }
    nx = b[nx] - 1;
    c++;
    // cout << "next btn " << nx + 1 << " cnt " << c << endl;
    if(c > n) break;
  }
  cout << -1 << endl;

}
