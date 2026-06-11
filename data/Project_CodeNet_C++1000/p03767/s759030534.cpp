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
  vector<ll> a(n * 3);
  for(int i = 0;i < n * 3;i++)cin >> a[i];
  sort(a.rbegin(),a.rend());
  ll res = 0;
  for(int i = 0;i < n;i++){
    res += a[i * 2 + 1];
  }
  cout << res << endl;
}