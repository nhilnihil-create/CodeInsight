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
  int sum = 0;
  cin >> a;
  int b = a.size();
  for(int i = 0;i<b;i++){
    for(int j = 0;j<b;j++){
      if(a.at(i)==a.at(j))sum++;
    }
    if(sum%2==1){
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}