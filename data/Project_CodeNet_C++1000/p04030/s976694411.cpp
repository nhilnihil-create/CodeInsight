#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string s;
  cin >> s;
  
  string ans = "";
  int n = s.size();
  int an = 0;
  rep(i,n){
    if(s[i] == '0'){
      ans += '0';
    }else if(s[i] == '1'){
      ans += '1';
    }else if(s[i] == 'B' && (ans[an-1] == '0' || ans[an-1] == '1')){
      ans.erase(an-1);
    }
    an = ans.size();
  }
  
  cout << ans << endl;
}
