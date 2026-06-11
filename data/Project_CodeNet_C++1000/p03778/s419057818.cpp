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
  ll w,a,b;
  cin >> w >> a >> b;
  if(a + w <= b)cout << b - a - w << endl;
  else if(b + w <= a)cout << a - b - w << endl;
  else cout << 0 << endl;
}