#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t N, A, B;
  cin >> N >> A >> B;
  if(N==1 && A!=B){
    cout << 0 << endl;
  }
  else if(N==1 && A==B){
    cout << 1 << endl;
  }
  else if(B<A){
    cout << 0 << endl;
  }
  else{
    cout << (B*(N-1)+A)-(B+A*(N-1))+1 << endl;
  }
}