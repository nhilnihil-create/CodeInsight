#include<bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,sum=0;
  cin >> A >> B >> C;
  bool a=false;
  for(int i=A;i<B*A+1;i+=A){
    sum+=A;
    if(sum%B==C){
      a=true;
      break;
    }
  }
  if(a){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}
