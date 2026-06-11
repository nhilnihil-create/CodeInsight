#include <bits/stdc++.h>
using namespace std;

int func(int N){
  if(N==1){
    return 1;
  }
  return N+func(N-1);
}

int main(){
  int N;
  cin >> N;
  cout << func(N) << endl;
}