#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,A,B;
  cin>>N>>A>>B;
  if(A>B){
    cout<<0<<endl;
  }
  else if(N==1 && A!=B){
    cout<<0<<endl;
  }
  else if(N==2){
    cout<<1<<endl;
  }
  else{
    cout<<((N-1)*B+A)-((N-1)*A+B)+1<<endl;
  }
}
