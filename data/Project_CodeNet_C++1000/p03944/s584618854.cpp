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
  ll w,h,n;
  cin >> w >> h >> n;
  ll wmax = w;
  ll wmin = 0;
  ll hmax = h;
  ll hmin = 0;
  for(int i = 0;i < n;i++){
    ll x,y,a;
    cin >> x >> y >> a;
    if(a == 1)wmin = max(wmin,x);
    if(a == 2)wmax = min(wmax,x);
    if(a == 3)hmin = max(hmin,y);
    if(a == 4)hmax = min(hmax,y);
    //cout << hmin << " " << hmax << " " << wmin << " " << wmax << endl;
  }
  cout << max((ll)0,hmax - hmin) * max((ll)0,wmax - wmin) << endl;
}