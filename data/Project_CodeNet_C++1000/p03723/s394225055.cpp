#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int A,B,C;
  cin>>A>>B>>C;
  if(A==B && B==C && !(A%2)){
    puts("-1");
    return 0;
  }
  int cnt=0;
  for(;!(A%2) && !(B%2) && !(C%2);cnt++){
    int a=(B+C)/2,b=(C+A)/2,c=(A+B)/2;
    A=a,B=b,C=c;
  }
  cout<<cnt<<endl;
}