#include <bits/stdc++.h>
using namespace std;
string evenodd(int x){
  int y=x/2;
  if(y*2==x){
  return "even";
  }
  return "odd";
}
int main(){
  int A,B,C;
  int x=0;
  cin>>A>>B>>C;
  string a,b,c;
  int count=0;
  a=evenodd(A);
  b=evenodd(B);
  c=evenodd(C);
  while(a=="even" && b=="even" && c=="even"){
count++;
    int Ae,Be,Ce;
    Ae=B/2+C/2;
    Be=A/2+C/2;
    Ce=A/2+B/2;
    A=Ae;
    B=Be;
    C=Ce;
      a=evenodd(A);
  b=evenodd(B);
  c=evenodd(C);

    if(A==B/2+C/2 && B==A/2+C/2 && C==A/2+B/2){
    cout<<-1<<endl;
     x=1;
    break;  
    
    }
  }
  if(x==0)
    cout<<count<<endl;
  
}