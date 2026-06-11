#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int n;
  int ans=10;
  cin>>n;
  for(long long int i=1;i<=sqrt(n);i++){
    if(n%i!=0) continue;
    string s=to_string(i);
    string t=to_string(n/i);
    int x=max(s.size(),t.size());
    ans=min(ans,x);
  }
  cout<<ans;

}
