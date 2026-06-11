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
  int c = a.size(),d = b.size();
  if(c>d) cout << "GREATER";
  else if(c<d) cout << "LESS";
  else {
    rep(i,c){
      if(a.at(i)>b.at(i)){
        cout << "GREATER";
        return 0;
      }
      else if(a.at(i)<b.at(i)){
        cout << "LESS";
        return 0;
      }
    }
    cout << "EQUAL";
  }
}