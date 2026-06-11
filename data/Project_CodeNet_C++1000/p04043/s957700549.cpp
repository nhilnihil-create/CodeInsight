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
  ll a,b,c;
  cin >> a >> b >> c;
  if(a + b + c == 17 && max({a,b,c}) == 7 && min({a,b,c}) == 5)cout << "YES" << endl;
  else cout << "NO" << endl;
}