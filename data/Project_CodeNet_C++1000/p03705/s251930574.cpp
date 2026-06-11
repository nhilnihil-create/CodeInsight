#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,A,B;
  cin>>N>>A>>B;
  if(A>B||(N==1&&A!=B)){
    cout<<"0"<<endl;
  }
  else{
    cout<<1+(N-2)*(B-A)<<endl;
  }
}

