#include<bits/stdc++.h>
using namespace std;


int main(){
  long long x,ans;
  cin >> x;
  if(x%11==0){
    ans=x/11;
    ans=ans*2;
  }else{
    ans=x/11;
    ans=ans*2;
    if(x%11<=6){
      ans++;
    }else{
      ans=ans+2;
    }
  }
  cout << ans << endl;
  return 0;
}
