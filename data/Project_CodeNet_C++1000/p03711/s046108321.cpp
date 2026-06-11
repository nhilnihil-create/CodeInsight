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
   ll x,y;
   cin >> x >> y;
  vector<ll> a = {1,3,5,7,8,10,12};
  vector<ll> b = {4,6,9,11};
  ll gx = 0;
  ll gy = 0;
  for(int i = 0;i < 7;i++){
    if(a[i] == x)gx = 1;
    if(a[i] == y)gy = 1;
  }
  for(int i = 0;i < 4;i++){
    if(b[i] == x)gx = 2;
    if(b[i] == y)gy = 2;
  }
  if(gx == gy)cout << "Yes" << endl;
  else cout << "No" << endl;
}