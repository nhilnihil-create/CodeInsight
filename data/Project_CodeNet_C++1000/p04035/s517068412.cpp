#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,L;
  cin>>N>>L;
  vector<int> A(N);
  for(int &i:A)cin>>i;
  for(int i=1;i<N;i++)
    if(A[i]+A[i-1]>=L){
      puts("Possible");
      for(int j=1;j<i;j++)cout<<j<<endl;
      for(int j=N-1;j>i;j--)cout<<j<<endl;
      cout<<i<<endl;
      return 0;
    }
  puts("Impossible");
}