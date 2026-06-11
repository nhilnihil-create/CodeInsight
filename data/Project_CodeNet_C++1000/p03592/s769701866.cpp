#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

int n, m, k;

int main(){
  cin >> n >> m >> k;
  string res = "No";
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= m; j++){
      if(i * m + j * n - 2 * i * j == k){
        res = "Yes";
        //cerr << i << " " << j << endl;
      }
    }
  }
  cout << res << endl;
  return 0;
}