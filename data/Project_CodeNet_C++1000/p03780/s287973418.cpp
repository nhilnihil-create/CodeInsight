/// referenced: https://beta.atcoder.jp/contests/abc056/submissions/2304275
#include<bits/stdc++.h>
using namespace std;
main(){
  int N,K;
  cin>>N>>K;
  vector<int>a(N);
  for(auto&x:a)cin>>x;
  sort(a.begin(),a.end());
  int ans=N,sum=0;
  for(int i=a.size()-1;i>=0;--i)
    if(sum+a[i]<K)
      sum+=a[i];
    else
      ans=i;
  cout<<ans<<endl;
}
