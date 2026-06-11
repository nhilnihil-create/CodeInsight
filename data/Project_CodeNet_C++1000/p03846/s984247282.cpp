#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  cin>>N;
  map<int,int> A;
  for(int i=0;i<N;i++){
    int j;
    cin>>j;
    A[j]++;
  }
  if(N%2==0){
    for(int i=1;i<N;i+=2)
      if(A[i]!=2){
        cout<<0<<endl;
        return 0;
      }
  }else if(A[0]!=1){
    cout<<0<<endl;
    return 0;
  }else
    for(int i=2;i<N;i+=2)
      if(A[i]!=2){
        cout<<0<<endl;
        return 0;
      }
  int j=1;
  for(int i=0;i<N/2;i++)
    j=j*2%1000000007;
  cout<<j<<endl;
}