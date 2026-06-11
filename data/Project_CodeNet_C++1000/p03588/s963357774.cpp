#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int j=0,k;
  for(int i=0;i<N;i++){
    int A,B;
    cin>>A>>B;
    if(j<A){
      j=A;
      k=B;
    }
  }
  cout<<j+k<<endl;
}