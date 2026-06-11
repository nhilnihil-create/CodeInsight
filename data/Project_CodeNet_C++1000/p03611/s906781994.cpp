#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,ans=0;
  cin>>n;
  vector<int> a(n);
  for(i=0;i<n;i++) cin>>a.at(i);
  sort(a.begin(),a.end());
  auto it1=a.begin();
  while(it1!=a.end()){
    auto it2=lower_bound(a.begin(),a.end(),(*it1)+3);
    ans=max(ans,(int)distance(it1,it2));
    it1=lower_bound(a.begin(),a.end(),(*it1)+1);
  }
  cout<<ans<<endl;
}