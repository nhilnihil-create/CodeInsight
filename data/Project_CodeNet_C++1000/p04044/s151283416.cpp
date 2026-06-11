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
  ll n,l;
  cin >> n >> l;
  vector<string> s(n);
  for(int i = 0;i < n;i++)cin >> s[i];
  sort(s.begin(),s.end());
  string res;
  for(int i = 0;i < n;i++)res += s[i];
  cout << res << endl;
}