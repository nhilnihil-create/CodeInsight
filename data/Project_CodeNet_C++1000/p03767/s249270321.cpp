#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main (){
  int n;
  cin>>n;
  vector<long long>a(3*n);
  rep(i,3*n)cin>>a[i];
  sort(a.begin(),a.end(),greater<int>());//降順にソート
  
  long long ans=0;
  
  for(int i=1;i<2*n;i+=2)ans+=a[i];
  cout<<ans<<endl;
  
  return 0;
}