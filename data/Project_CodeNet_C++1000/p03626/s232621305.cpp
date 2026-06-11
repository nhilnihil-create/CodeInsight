#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;

void solve(){
  int n, s; cin >> n;
  vector<vector<char> > c(2, vector<char>(n));
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < n; j++){
      cin >> c[i][j];
    }
  }

  ll ans, mod = 1000000007;
  bool yoko;
  if(n > 1 && c[0][0] == c[0][1]){
    ans = 3 * 2;
    s = 2;
    yoko = true;
  }
  else{
    ans = 3;
    s = 1;
    yoko = false;
  }

  //n = 12;
  for(int i = s; i < n; i++){
    if(i < n - 1 && c[0][i] == c[0][i + 1]){
      if(yoko == false) ans = (ans * 2) % mod;
      else ans = (ans * 3) % mod;
      //cout << c[0][i] << c[0][i + 1] << " " << ans << " ";
      i++;
      yoko = true;
    }
    else{
      if(yoko == false) ans = (ans * 2) % mod;
      //cout << c[0][i] << c[1][i] << " " << ans << " ";
      yoko = false;
    }
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
