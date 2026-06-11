#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  cin>>N;
  vector<int> A(N*3);
  for(int &i:A)
    cin>>i;
  sort(A.begin(),A.end());
  int j=0;
  for(int i=N;i<N*3;i+=2)
    j+=A[i];
  cout<<j<<endl;
}