#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,g=0;
  cin>>N;
  vector<int> A(N);
  for(int &i:A){
    cin>>i;
    g+=i;
  }
  if(g%10!=0){
    cout<<g<<endl;
    return 0;
  }
  sort(A.begin(),A.end());
  for(int i:A)
    if(i%10!=0){
      cout<<g-i<<endl;
      return 0;
    }
  cout<<0<<endl;
}