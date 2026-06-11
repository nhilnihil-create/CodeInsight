#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  string s; cin>>s;
  int n = s.size();
  ll ans = 0;
  for(int bit=0; bit<(1<<(n-1)); ++bit){
    string ss = "";
    for (int i=0; i<n; ++i){
      ss += s[i];
      if (bit & (1<<i)){
        ans += stoll(ss);
        ss = "";
      }
    }
    ans += stoll(ss);
    ss = "";
  }
  cout << ans << endl;
}
