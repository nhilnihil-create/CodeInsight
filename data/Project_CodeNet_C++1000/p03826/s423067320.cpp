#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D;
  cin>>A>>B>>C>>D;
  int S1=A*B;
  int S2=C*D;
  if(S1<=S2){
    cout<<S2<<endl;
  }
  else{
    cout<<S1<<endl;
  }
}
    
