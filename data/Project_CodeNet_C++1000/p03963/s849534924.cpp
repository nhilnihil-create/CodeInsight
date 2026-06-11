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
  ll res = 0;
  res = k;
  for(int i = 1;i < n;i++)res *= k - 1;
  cout << res << endl;
}