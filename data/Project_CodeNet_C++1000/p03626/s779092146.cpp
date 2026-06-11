#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string s1,s2;
  cin >> s1;
  cin >> s2;
  int i = 0;
  long ans = 1;
  long mod = 1000000007;
  int mae = 0;//0:: = 1::|
  for(i=0;i<n;i++){
    if(i==0){
      if(s1[i]==s2[i]){
        ans *= 3;
        mae = 0;
      }else{
        ans *= 6;
        mae = 1;
        i++;
      }
    }else{
      if(s1[i]==s2[i]){
        if(mae==0){
          ans *= 2;
          ans %= mod;
        }
        mae = 0;
      }else{
        if(mae==0){
          ans *= 2;
          ans %= mod;
        }else{
          ans *= 3;
          ans %= mod;
        }
        mae = 1;
        i++;
      }
    }
  }
  cout << ans << endl;
}
