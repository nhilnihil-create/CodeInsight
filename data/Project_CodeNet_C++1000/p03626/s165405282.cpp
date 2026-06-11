#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1000000007;
signed main(){
  int N;
  cin>>N;
  vector<string> A(2);
  for(string &S:A)
    cin>>S;
  int ans=1,i=1;
  bool b=true;
  if(A[0][0]==A[1][0])
    b=true,ans=3;
  else
    b=false,i++,ans=6;
  for(;i<N;i++){
    if(A[0][i]==A[1][i]){
      if(b)
        ans=ans*2%M;
      b=true;
    }
    else{
      if(b)
        ans=ans*2%M;
      else
        ans=ans*3%M;
      b=false,i++;
    }
  }
  cout<<ans<<endl;
}