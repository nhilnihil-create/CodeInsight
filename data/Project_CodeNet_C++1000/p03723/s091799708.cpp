#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C;
  int X,Y,Z;
  int count=0;
  cin>>A>>B>>C;
  if(A==B && B==C && A%2==0){
    cout<<-1<<endl;
    return 0;
  }
  while(A%2==0 && B%2==0 && C%2==0){
    A/=2;
    B/=2;
    C/=2;
    X=A; Y=B; Z=C;
    A=Y+Z; B=X+Z; C=X+Y;
    count++;
  }
  cout<<count<<endl;
  return 0;
}

    
