#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N,A,B,C,D;
  cin>>N>>A>>B>>C>>D;
  int64_t x=B-A;
  string ans="NO";
  for(int64_t i=0;i<N;i++){
  if(C*i-D*(N-1-i)<=x && x<=D*i-C*(N-1-i)){ans="YES"; break;}
  }cout<<ans<<endl;
  return 0;
}