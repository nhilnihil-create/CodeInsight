#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  if(A <= C){
  if(B<=C){
    cout << 0 << endl;
  }
  else{
    cout << min(B,D)-C << endl;
  }
}

else if(A > C){
  if(D<=A){
    cout << 0 << endl;
  }
  else {
    cout <<min(B,D)-A << endl;
  }
  
}
}