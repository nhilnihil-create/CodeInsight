#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  cin>>N;
  vector<int> A(N);
  int k=0,ans=0;
  for(int &i:A){
    cin>>i;
    ans+=(i+k)/2;
    if(i==0)
      k=0;
    else
      k=(i+k)%2;
  }
  cout<<ans<<endl;
}