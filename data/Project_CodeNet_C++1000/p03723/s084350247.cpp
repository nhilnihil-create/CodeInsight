#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int A,B,C;
  cin>>A>>B>>C;
  int ans=0;
  if(A==B&&B==C){
    if(A%2==0&&B%2==0&&C%2==0){
      cout<<-1<<endl;
      return 0;
    }
  }
  int i=0;
  for(;A%2==0&&B%2==0&&C%2==0;i++){
    int a=A;
    int b=B;
    int c=C;
    A=0;
    B=0;
    C=0;
    A=b/2+c/2;
    B=a/2+c/2;
    C=a/2+b/2;
  }
  cout<<i<<endl;
}