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
  if(a % 2 == 1 && b % 2 == 1 && c % 2 == 1){
    cout << min({a*b,b*c,a*c}) << endl;
  }
  else{
    cout << 0 << endl;
  }
}