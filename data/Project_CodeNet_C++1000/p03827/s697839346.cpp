#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0,ans = 0, tmp = 0;
  string S;
  cin >> N >> S;
  rep(i,N){
    if(S[i] == 'I'){
      tmp++;
      ans = max(tmp,ans);
    }
    else{
      tmp--;
      ans = max(tmp,ans);
    }
  }
  cout << ans;
}