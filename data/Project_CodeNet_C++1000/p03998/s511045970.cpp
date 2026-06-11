#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string A,B,C;
  cin>>A>>B>>C;
  char N='a';
  bool EMP=true;
  string win="";
  while(EMP){
    if(N=='a'){
      if(A.size()==0){
        EMP=false;
        win+='A';
        break;
      }
      N=A[0];
      A.erase(A.begin()+0);
    }
    if(N=='b'){
      if(B.size()==0){
        EMP=false;
        win+='B';
        break;
      }
      N=B[0];
      B.erase(B.begin()+0);
    }
    if(N=='c'){
      if(C.size()==0){
        EMP=false;
        win+='C';
        break;
      }
      N=C[0];
      C.erase(C.begin()+0);
    }
  }
  cout<<win<<endl;
  return 0;
}