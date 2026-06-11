#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int ans=0;
  if(abs(a)>abs(b)){
    ans+=abs(a)-abs(b);
    if(a>0)
      ans++;
    if(b>0)
      ans++;
  }else if(abs(a)<abs(b)){
    ans+=abs(b)-abs(a);
    if(a<0)
      ans++;  
    if(b<0)
      ans++;
  }else{
    ans=1;
  }
  cout << ans << endl;
  return 0;
}