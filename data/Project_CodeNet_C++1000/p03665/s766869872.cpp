#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,P,g=0,n=0,m=0;
  cin>>N>>P;
  vector<int> A(N);
  for(int &i:A){
    cin>>i;
    if(i%2==1){
      cout<<(int)pow(2,N-1)<<endl;
      return 0;
    }
  }
  if(P==1)
    cout<<0<<endl;
  else
    cout<<(int)pow(2,N)<<endl;
}