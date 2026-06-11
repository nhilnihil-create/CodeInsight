#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007;

void solve()
{
  int n; cin >> n;
  string s;
  cin >> s;
  int bra = 0;
  int ket = 0;
  int cnt_bra;
  int cnt_ket;
  for(int i = 0; i < n; ++i){
    if(s[i] == ')'){
      cnt_bra = 0;
      cnt_ket = 1;
      int flag = 0;
      for(int j = i-1;j >= 0; j--){
        if(s[j] == '(')cnt_bra++;
        else cnt_ket++;
        if(cnt_bra == cnt_ket){
          flag = 1;
          break;
        }
      }
      if(!flag) bra++;
    } else {
      cnt_bra= 1;
      cnt_ket = 0;
      int flag2 = 0;
      for(int j = i+1;j < n; ++j){
        if(s[j] == ')')cnt_ket++;
        else cnt_bra++;
        if(cnt_bra == cnt_ket){
          flag2 = 1;
          break;
        }
      }
      if(!flag2) ket++;
    }
  }
  string ans;
  for(int i = 0; i < bra; i ++) {
    char b = '(';
    ans += b;
  }
  ans += s;
  for(int i = 0; i < ket; i ++) {
    char k = ')';
    ans += k;
  }
  cout << ans << endl;
}

int main()
{
  solve();
  return 0;
}
