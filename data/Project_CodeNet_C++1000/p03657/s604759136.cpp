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
  ll a,b;
  cin >> a >> b;
  a %= 3;
  b %= 3;
  ll c = a + b;
  c %= 3;
  if(a*b*c == 0)cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}