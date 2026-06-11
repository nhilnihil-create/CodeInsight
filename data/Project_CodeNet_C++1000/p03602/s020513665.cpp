#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli>> mat;

lli n;
mat a;
lli ans;

void error(){
  cout << -1 << endl;
  exit(0);
}

int main(){
  cin >> n;
  a = mat(n,vll(n));
  for(lli i = 0;i < n;i++){
    for(lli j = 0;j < n;j++){
      cin >> a[i][j];
    }
  }
  for(lli i = 0;i < n;i++){
    for(lli j = 0;j < n;j++){
      ans += a[i][j];
    }
  }
  for(lli i = 0;i < n;i++){
    for(lli j = 0;j < n;j++){
      for(lli k = 0;k < n;k++){
        if(a[i][j] > a[i][k] + a[k][j]) error();
        if(a[i][j] == a[i][k] + a[k][j] && i != k && j != k){
          ans -= a[i][j];
          break;
        }
      }
    }
  }
  cout << ans/2 << endl;
  return 0;
}
