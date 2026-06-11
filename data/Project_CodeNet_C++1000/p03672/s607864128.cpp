#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T>
bool PN(T x){ if (x <= 1) return false; if (x == 2) return true; for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false; return true;}
const ll MOD = 1e9+7;
long long Comb(int n, int i){long long ans = 1; if(i == 0 || i == n) return 1; else {for(int j = 1; j <= i; ++j){
      ans *=(n+1-j);
      ans /= j;
      ans %= MOD;} }return ans;}


void solve(){
  string s;
  cin >> s;
  s = s.substr(0,s.size()-1);
  int flag = 0;
  while(1){
      if(s.size()%2==1) {
        s = s.substr(0,s.size()-1);
        continue;
      }
      else {
          int judge = 0;
          for(int i = 0; i < s.size()/2; ++i){
              if(s[i] != s[s.size()/2+i]) {
                s = s.substr(0,s.size()-1);
                judge = 1;
                break;
              }
          }
          if(!judge) flag = 1;
      }
      if(flag) {
          cout << s.size() << endl;
          return;
      }
  }
}

int main(void){
    solve();
    return 0;
}
