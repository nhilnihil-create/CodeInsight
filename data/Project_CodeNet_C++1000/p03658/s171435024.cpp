#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,i,ans=0;
  cin>>n>>k;
  vector<int> l(n);
  for(i=0;i<n;i++) cin>>l.at(i);
  sort(l.begin(),l.end());
  reverse(l.begin(),l.end());
  for(i=0;i<k;i++) ans+=l.at(i);
  cout<<ans<<endl;
}