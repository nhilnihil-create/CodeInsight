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
  string a,b;
  cin >> a >> b;
  int c = a.size(),d=b.size();
  if(c==d){
    rep(i,c){
      cout << a.at(i) << b.at(i);
    }
    cout << endl;
  }
  else{
    rep(i,d){
      cout << a.at(i) << b.at(i);
    }
    cout << a.at(c-1) << endl;
  }
}
