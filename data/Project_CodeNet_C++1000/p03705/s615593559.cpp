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
  ll n,a,b;
  cin >> n >> a >> b;
  ll res = 0;
  if(n == 1 && a != b)res = 0;
  else if(a > b){
    res = 0;
  }
  else{
    res = b * (n - 1) + a - (a * (n - 1) + b) + 1;
  }
  cout << res << endl;
}