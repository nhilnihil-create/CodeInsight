#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A;
  
  cin >> N;
  cin >> A;
  
  if ( 1<=N<=100 && 0<=A<=N*N ){
    cout << N*N - A << endl;
  }
  else {
    cout << "error" << endl;
  }
}
