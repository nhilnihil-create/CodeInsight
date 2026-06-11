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
  string a;
  cin >> a;
  int b = a.size();
  vi ans(26,1);
  rep(i,b){
    ans.at(a.at(i)-'a')=0;
  }
  rep(i,26){
    if(ans.at(i)) {
      char aaa = 'a' + i;
     cout << aaa;
     return 0;
  }
  }
  cout << "None";
}