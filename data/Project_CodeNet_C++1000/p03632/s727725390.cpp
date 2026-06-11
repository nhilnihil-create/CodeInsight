#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  if(A<C){
    if(B<D){
      cout << max(B-C, 0) << endl;
    }
    else{
      cout << D-C << endl;
    }
  }
  else{
    if(B<D){
      cout << B-A << endl;
    }
    else{
      cout << max(D-A, 0) << endl;
    }
  }
}
