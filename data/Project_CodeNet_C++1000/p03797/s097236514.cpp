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
  ll s,c;
  cin >> s >> c;
  ll res = 0;
  if(c / 2 <= s){
    res = c / 2;
  }
  else{
    res += s;
    c -= s * 2;
    res += c / 4;
  }
  cout << res << endl;
}