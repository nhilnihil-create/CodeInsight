#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  string s;
  cin >> s;
  int bit = 0;
  int end = pow(2, s.size()-1);
  ll int ans = 0;
  while(!(bit & end)) {
    ll int thisans = 0;
    ll int num = 0;
    rep(i, s.size()-1) {
      num += (int)(s[i]-48);
      if(bit & (1<<i)) {
//        cout << "true " << thisans << " + " << num << endl; 
        thisans += num;
        num = 0;
      } else {
        num *= 10;
//        cout << "false " << num << endl;
      }
    }
    thisans += num + s[s.size()-1]-48;
    ans += thisans;
    ++bit;
//    cout << thisans << endl;
  }
  
  cout << ans << endl;
  return 0;
}
