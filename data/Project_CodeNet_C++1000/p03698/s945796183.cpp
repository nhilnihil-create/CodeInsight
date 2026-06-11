#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string s;
  cin >> s;
  
  bool app[27];
  rep(i,27) app[i] = false;
  
  int n = s.size();
  rep(i,n){
    if(!app[s[i] - 'a']){
      app[s[i] - 'a'] = true;
    }else{
      cout << "no" << endl;
      return 0;
    }
  }
  
  cout << "yes" << endl;
}
