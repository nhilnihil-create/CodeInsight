#include <bits/stdc++.h>
using namespace std;
int sum(int X){
  if(X==0){
    return 0;
  }
  return X+sum(X-1);
}

int main(){
  int N;
  cin >> N;
  cout << sum(N) << endl;
}