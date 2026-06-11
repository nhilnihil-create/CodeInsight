#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n=s.size();
  long long ans=0;
  for(int i=0;i<(1<<(n-1));i++){
    long long tmp=0;
    for(int j=0;j<n-1;j++){
      tmp*=10;
      tmp+=s[j]-'0';
      if(i&(1<<j)){
        ans+=tmp;
        tmp=0;
      }
    }
    tmp*=10;
    tmp+=s[n-1]-'0';
    ans+=tmp;
  }
  cout<<ans<<endl;
  return 0;
}
