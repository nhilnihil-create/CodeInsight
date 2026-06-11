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
  vector<ll> p(n);
  for(int i = 0;i < n;i++)cin >> p[i],p[i]--;
  vector<ll> a(n);
  vector<ll> b(n);
  ll add = 40000;
  for(int i = 0;i < n;i++){
    a[i] += add * i + 1;
    a[p[i]] += i + 1;
    b[n - i - 1] = add * i + 1;
  }
  for(int i = 0;i < n;i++)cout << a[i] << " ";
  cout << endl;
  for(int i = 0;i < n;i++)cout << b[i] << " ";
  cout << endl;
}