#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <iomanip>
#include <algorithm>
using namespace std;
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()

int main() {
  int a,sum=0;
  cin >> a;
  vi sco(a);
  rep(i,a){
    cin >> sco.at(i);
    sum += sco.at(i);
  }
  int dri,tmp1,tmp2;
  cin >> dri;
  rep(i,dri){
    cin >> tmp1 >> tmp2;
    tmp1--;
    cout << sum - sco.at(tmp1) + tmp2 << endl;
  }
}