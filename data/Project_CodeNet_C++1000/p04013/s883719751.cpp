#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

int n, a;

void solve(){
  cin >> n >> a;
  vector<int> x(n + 1);
  for(int i = 1; i <= n; i++){
    cin >> x[i];
  }
  vector<vector<vector<long long int> > > d(n + 1, vector<vector<long long int> >(n + 1, vector<long long int>(n * a + 1)));
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= n; j++){
      for(int k = 0; k <= n * a; k++){
        if(i == 0 && j == 0 && k == 0) d[i][j][k] = 1;
        else if(i >= 1 && k < x[i]) d[i][j][k] = d[i - 1][j][k];
        else if(i >= 1 && j >= 1 && k >= x[i]) d[i][j][k] = d[i - 1][j][k] + d[i - 1][j - 1][k - x[i]];
        else d[i][j][k] = 0;
      }
    }
  }
  unsigned long long int ans = 0;
  for(int j = 1; j <= n; j++){
    ans += d[n][j][j * a];
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
