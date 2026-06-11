#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n = 0;
  cin >> n;
  ll res = 0;
  for(int i = 0;i < n;i++){
    ll ina,inb;
    cin >> ina >> inb;
    res += inb - ina + 1;
  }
  cout << res << endl;
}

