#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>

int main() {
  int64_t N,P;
  cin>>N>>P;
  vector<int>A(N);
  bool even=true;
  for(int i=0;i<N;i++){
    cin>>A[i];
    if(A[i]%2!=0){even=false;}
  }
  if(even){
    if(P%2==0){cout<<(int64_t)pow(2,N)<<endl;}
    else{cout<<0<<endl;}
  }
  else{
    cout<<(int64_t)pow(2,N-1)<<endl;
  }
  return 0;
}