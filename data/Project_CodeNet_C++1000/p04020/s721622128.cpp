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
  vector<ll> num(n);
  for(int i = 0;i < n;i++)cin >> num[i];
  ll res = 0;
  ll memo = 0;
  for(int i = 0;i < n;i++){
    if(num[i] == 0){
      res += memo / 2;
      memo = 0;
    }
    memo += num[i];
  }
  res += memo / 2;
  cout << res << endl;
  return 0;
}