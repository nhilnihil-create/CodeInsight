#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  ll ans;
  ll mod = 1e9+7;
  bool vt;
  for(int i=0; i<n; i++){
    if(s1[i]==s2[i]){
      if(i==0){
        ans = 3LL;
        vt = true;
        continue;
      }
      if(vt){
        ans *= 2;
        ans %= mod;
      }else{
        vt = true;
      }
    }else{
      if(i==0){
        ans = 6LL;
        vt = false;
        i++;
        continue;
      }
      if(vt){
        ans *= 2;
        ans %= mod;
        i++;
        vt = false;
      }else{
        ans *= 3;
        ans %= mod;
        i++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
