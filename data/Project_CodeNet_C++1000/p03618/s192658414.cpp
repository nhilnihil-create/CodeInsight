#include<bits/stdc++.h>
using namespace std;
int main(){
  string a;
  cin >> a;
  vector<int>alp(26);
  int i;
  for(i=0;i<a.length();i++){
    alp[(int)(a[i]-'a')]++;
  }
  long ans = a.length();
  ans *= a.length()-1;
  ans/=2;
  ans ++;
  for(i=0;i<26;i++){
    ans -= (long)alp[i]*(alp[i]-1)/2;
  }
  cout << ans<<endl;
}
