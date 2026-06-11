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
  int a,b;
  string tmp;
  cin >> a >> b;
  rep(i,b+2){
    cout << "#";
  }
  cout << endl;
  rep(i,a){
    cin >> tmp;
    cout << "#" << tmp << "#" << endl;
  }
  rep(i,b+2){
    cout << "#";
  }
  cout << endl;
}