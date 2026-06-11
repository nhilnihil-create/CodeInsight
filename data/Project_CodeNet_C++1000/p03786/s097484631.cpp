#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int &i:A)
    cin>>i;
  sort(A.begin(),A.end());
  vector<int> B(N);
  B[0]=0;
  for(int i=0;i<N-1;i++)
    B[i+1]=B[i]+A[i];
  for(int i=N-1;i>=0;i--){
    if(B[i]*2<A[i]){
      cout<<N-i<<endl;
      return 0;
    }
  }
  cout<<N<<endl;
}