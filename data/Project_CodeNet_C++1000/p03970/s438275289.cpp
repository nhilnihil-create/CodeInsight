#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  string t = "CODEFESTIVAL2016";
  string s;
  cin >> s;
  
  ll ans = 0;
  for (int i = 0; i < t.size(); i++){
    ans += (t[i] != s[i]);
  }

  cout << ans << endl;
  

  return 0;
}
