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
  ll all = a + b + c;
  if(max({a,b,c}) == all - max({a,b,c}))cout << "Yes" << endl;
  else cout << "No" << endl;
}