#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  if(N==1){
    N=14;
  }
  if(M==1){
    M=14;
  }
  if(N<M){
    cout << "Bob" << endl;
  }
  else if(N==M){
    cout << "Draw" << endl;
  }
  else{
    cout << "Alice" << endl;
  }
}
