#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  ll a,b,ans;
  ll c = 0;
  cin >> a >> b;
  ans = b;
  
   a--;
  while(a>c){
   ans *= b-1;
   a--;
  }
  cout << ans;
}
