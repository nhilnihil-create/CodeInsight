#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  cin>>N;
  int t=1,a=1;
  for(int i=0;i<N;i++){
    int T,A;
    cin>>T>>A;
    int j=max((t+T-1)/T,(a+A-1)/A);
    t=j*T;
    a=j*A;
  }
  cout<<t+a<<endl;
}