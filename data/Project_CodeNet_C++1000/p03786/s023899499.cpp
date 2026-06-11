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
  vector<ll> a(n);
  for(int i = 0;i < n;i++)cin >> a[i];
  sort(a.begin(),a.end());
  ll now = 0;
  ll res = 0;
  for(int i = 0;i < n - 1;i++){
    now += a[i];
    if(now * 2 < a[i + 1]){
      res = i + 1;
      //cout << i << " "<<  res << endl;
    }
  }
  cout << n - res << endl;
}