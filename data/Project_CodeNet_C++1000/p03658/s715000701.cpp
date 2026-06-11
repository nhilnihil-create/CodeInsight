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
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  for(int i = 0;i < n;i++)cin >> a[i];
  sort(a.rbegin(),a.rend());
  ll res = 0;
  for(int i = 0;i < k;i++)res += a[i];
  cout << res << endl;
}