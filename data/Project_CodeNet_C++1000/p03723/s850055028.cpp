#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
  int A,B,C;
  cin>>A>>B>>C;
  int count=0;
  while(A%2==0&&B%2==0&&C%2==0){
    if(A==B&&B==C){cout<<-1<<endl;return 0;}
    int a=A;int b=B;int c=C;
   A=(b+c)/2;B=(a+c)/2;C=(a+b)/2;count++;
  }
  cout<<count<<endl;
  return 0;
}