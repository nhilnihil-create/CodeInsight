#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  int a,sum=0;
  cin >> a;
  int b,c;
  rep(i,a){
    cin >> b >> c;
    sum += c - b + 1;
  }
  cout << sum << endl;
}