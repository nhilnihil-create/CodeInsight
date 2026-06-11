#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
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
  for(int i = b-2;i>=0;i-=2){
    bool exist = true;
    for(int j = 0;j<i/2;j++){
      if(a.at(j)!=a.at(j+i/2)) exist = false;
    }
     if(exist) {
       cout << i << endl;
       return 0;
     }
  }
}