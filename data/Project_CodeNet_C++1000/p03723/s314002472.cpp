#include<bits/stdc++.h>
using namespace std;
int main(){
  long double A,B,C;cin>>A>>B>>C;
  if(A==B&&B==C&&A!=1)cout<<-1<<endl;
  else{
    long D,E,F;long long G,H,I;int M;
    for(int X=0;;X++){
      D=A;E=B;F=C;
      A=E/2+F/2;B=D/2+F/2;C=D/2+F/2;
      G=E/2+F/2;H=D/2+F/2;I=D/2+F/2;
      if(F%2==1||D%2==1||E%2==1){
        M=X;break;
      }
    }
    cout<<M<<endl;
  }
}