#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin>>N;
  int64_t A=1;
  for(int64_t i=2;i*i<=N;i++){
    if(N%i==0){
      A=i;
    }
  }
  int64_t X=N/A,Z=0;
  while(X!=0||A!=0){
    Z++;
    X/=10;
    A/=10;
  }
  cout<<Z<<endl;
}

