#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <iomanip>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  ll a,b,tmp,Min;
  int ans;
  cin >> a >> b;
  vector<vector<ll>> stu(a, vector<ll>(2));
  vector<vector<ll>> chp(b, vector<ll>(2));
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> stu.at(i).at(j);
    }
  }
  for (int i = 0; i < b; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> chp.at(i).at(j);
    }
  }
  for (int i = 0; i < a; i++) {
    Min = 100000000000;
    for (int j = 0; j < b; j++) {
      tmp = 0;
      for (int k = 0; k < 2; k++) {
        tmp += abs(stu.at(i).at(k) - chp.at(j).at(k));
      }
       if(Min>tmp){
         Min = tmp;
         ans = j + 1;
       }
    }
      cout << ans <<  endl;;
                   }
  }