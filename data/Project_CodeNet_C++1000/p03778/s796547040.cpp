#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vec1;
typedef vector<string> vec2;
typedef vector<double> vec3;
#define rep(i,n) for(int i=0;i<(n);i++)
const int MOD = 1000000007;

int main() {
  int W, a, b;
  cin >> W >> a >> b;
  
  if(a < b) {
    if((b - (a + W)) <= 0) {
      cout << 0 << endl;
    } else {
      cout << b - (a + W) << endl;
    }
  } else if(a > b) {
    if((a - (b + W)) <= 0) {
      cout << 0 << endl;
    } else {
      cout << a - (b + W) << endl;
    }
  } else {
    cout << 0 << endl;
  }
}