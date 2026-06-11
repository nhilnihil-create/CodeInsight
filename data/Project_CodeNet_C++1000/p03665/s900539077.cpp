#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N,P;
  cin>>N>>P;
  for(int64_t i=0;i<N;i++){
    int64_t A;
    cin>>A;
    if(A%2==1){
      cout<<(int64_t)pow(2,N-1)<<endl;
      return 0;
    }
  }
  cout<<(int64_t)pow(2,N)*(1-P)<<endl;
}