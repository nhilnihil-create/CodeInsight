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
  ll a,c;
  string b;
  cin >> a >> b >> c;
  if(b == "+")cout << a+c << endl;
  else cout << a - c << endl;
}
