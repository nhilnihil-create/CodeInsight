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
  ll n;
  cin >> n;
  ll res = 1000000;
  for(int i = 1;i <= sqrt(n);i++){
    if(n % i == 0){
      ll big = n / i;
      string s = to_string(big);
      res = min(res,(ll)s.size());
    }
  }
  cout << res << endl;
}