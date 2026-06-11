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
  string res;
  if(a <= 0 && b >= 0)res = "Zero";
  else if(a > 0)res = "Positive";
  else{
    if((b - a + 1) % 2 == 1)res = "Negative";
    else res = "Positive";
  }
  cout << res << endl;
}