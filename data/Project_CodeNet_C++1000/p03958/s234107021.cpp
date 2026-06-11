#include<bits/stdc++.h>
using namespace std;
int main(){
int K,T;
  cin>>K>>T;
  vector<int>a(T);
  for(int i=0;i<T;i++)
    cin>>a.at(i);
  int sum=0;
  for(int i=0;i<T;i++){
  sum+=a.at(i);
  }sort(a.begin(),a.end());
  int ans=2*a.at(T-1)-1-sum;
  ans=max(0,ans);
  cout<<ans<<endl;
   return 0;
}