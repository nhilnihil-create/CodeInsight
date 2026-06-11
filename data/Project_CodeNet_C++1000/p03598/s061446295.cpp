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
  int a, b,ans=0,tmp;
  cin >> a >> b;
  rep(i,a){
    cin >> tmp;
    ans += min(tmp,b-tmp)*2;
  }
  cout << ans;
}