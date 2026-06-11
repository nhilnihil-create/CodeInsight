#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
const long long MOD = 1000000007LL;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
int main(){
  int n;
  cin >> n;
  long long ans = 1e16;
  long long x,y;
  rep(i,n){
    cin >> x >> y;
    ans = min(x+y,ans);
  }
  cout << ans << endl;
}
