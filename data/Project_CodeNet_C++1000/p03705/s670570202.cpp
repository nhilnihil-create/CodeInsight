#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,A,B;
  cin>>N>>A>>B;
  if(A>B)puts("0");
  else if(N==1){
    if(A==B)puts("1");
    else puts("0");
  }else cout<<B*(N-1)+A-(B+A*(N-1))+1<<endl;
}