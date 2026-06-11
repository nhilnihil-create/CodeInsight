#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  string s;
  cin >> s;
  int len= s.size(); 
  ll ans=0; 

  for(int t=0; t<1<<(len-1); t++){
    ll num=s[0]-'0'; 
    for(int i=0; i<len-1; i++){
      if(t&(1<<i)){
        ans+=num;
        num=0;
      }
      num=num*10+s[i+1]-'0';
    }
    ans+=num;
  }
  cout << ans << endl;
  return 0;
}