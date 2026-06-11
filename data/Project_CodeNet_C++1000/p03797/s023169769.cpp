#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  long long n, m, ans = 0; cin >> n >> m;
  if(2 * n <= m){
    ans = n + (m - 2 * n) / 4;
  }
  else{
    ans = m / 2;
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
