#include<iostream>
#include<algorithm>
using namespace std;
int main(){

  long long A,B,C;
  cin>>A>>B>>C;
  if(A%2==0||B%2==0||C%2==0){
  
    cout<<0;
    return 0;
  }
  long long ans=0;
  long long anscheck=0;
  anscheck=B*C;
  ans=anscheck;
  anscheck=A*C;
  ans=min(ans,anscheck);
  anscheck=A*B;
  ans=min(ans,anscheck);
  cout<<ans;
  return 0;
}