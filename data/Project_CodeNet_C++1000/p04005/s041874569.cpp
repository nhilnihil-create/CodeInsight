#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t A, B, C;
  cin >> A >> B >> C;
  if(A%2+B%2+C%2<3){
    cout << 0 << endl;
  }
  else{
    cout << min(A*B, min(B*C, C*A)) << endl;
  }
}