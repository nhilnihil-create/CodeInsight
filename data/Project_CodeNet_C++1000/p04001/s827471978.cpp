#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ll ans = 0;
  string s;
  cin >> s;
  if(s.size()==1) ans = stoll(s);
  else {
    for(int i=0; i<s.size(); i++) {
      for(int j=1; j<=s.size()-i; j++) {
        if(i==0 && j==s.size()) ans+=stoll(s);
        else if(i==0 || i==s.size()-j) ans+=(stoll(s.substr(i,j)))*pow(2,(s.size()-1-j));
        else ans+=(stoll(s.substr(i,j)))*pow(2,(s.size()-2-j));
      }
    }
  }
  cout << ans << endl;
}
