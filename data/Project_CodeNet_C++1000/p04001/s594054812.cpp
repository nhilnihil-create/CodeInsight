#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int64_t n=s.size(),ans=0;
  for(int64_t mask=0;mask<(1<<n-1);mask++){
    int64_t num=s[0]-'0';
    for(int64_t i=0;i<n-1;i++){
      if(mask&(1<<i)){
        ans+=num;
        num=0;
      }
      num=num*10+s[i+1]-'0';
    }
    ans+=num;
  }
  cout << ans << endl;
}