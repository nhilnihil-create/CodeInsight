#include <bits/stdc++.h>
using namespace std;

int main() {
  string A="dream",B="dreamer",C="erase",D="eraser",S,T="";
  cin>>S;
  reverse(S.begin(),S.end());
  reverse(A.begin(),A.end());
  reverse(B.begin(),B.end());
  reverse(C.begin(),C.end());
  reverse(D.begin(),D.end());
  int N=S.size();
  int a=0;
  while(a<N-2){
    if(S[a]==A[0]&&S[a+1]==A[1]){
      T+=A;
      a+=5;
    }
    else if(S[a]==B[0]&&S[a+1]==B[1]&&S[a+2]==B[2]){
      T+=B;
      a+=7;
    }
    else if(S[a]==C[0]&&S[a+1]==C[1]){
      T+=C;
      a+=5;
    }
    else if(S[a]==D[0]&&S[a+1]==D[1]&&S[a+2]==D[2]){
      T+=D;
      a+=6;
    }
    else{
      break;
    }
  }
  if(S==T){
cout<<"YES"<<endl;
  }
  else{
cout<<"NO"<<endl;
  }
}