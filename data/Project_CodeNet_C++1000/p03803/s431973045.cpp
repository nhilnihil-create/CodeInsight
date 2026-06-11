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
  if(a == 1)a = 100;
  if(b == 1)b = 100;
  if(a == b)cout << "Draw" << endl;
  else if(a > b)cout << "Alice" << endl;
  else cout << "Bob" << endl;
}