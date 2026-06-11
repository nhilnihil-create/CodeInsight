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
  int a,b,c;
  cin >> a >> b;
  vi ans(a,0);
  rep(i,b*2){
    cin >> c;
    c--;
    ans.at(c)++;
  }
  rep(i,a){
    cout << ans.at(i) << endl;
  }
}