#include <bits/stdc++.h>
using namespace std;



int main() {
  int64_t N,A,B;
  cin>>N>>A>>B;
  
  if(N==1){
    if(A==B){
      cout<<1<<endl;
    }
    else{
      cout<<0<<endl;
    }
  }
  else{
    if(A>B){
      cout<<0<<endl;
    }
    else if(A==B){
      cout<<1<<endl;
    }
    else{
      cout<<(B-A)*(N-2)+1<<endl;
    }
  }
  
}