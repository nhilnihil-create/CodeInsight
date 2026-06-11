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
  int b = a.size(),c,d;
  for(int i = 0;i<b;i++){
    if(a.at(i)=='A'){
      c = i;
      break;
    }
  }
  for(int i = b-1;i>0;i--){
    if(a.at(i)=='Z') {
      d = i;
      break;
    }
  }
  cout << d-c+1;
}