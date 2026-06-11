#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, tmp, ans;
  cin >> N;
  if (N == 1){
    cout << 1;
    return 0;
  }
  for (int i = 1; i <= 7; i++){
    tmp = pow(2, i);
    if(tmp > N){
      cout << pow(2, i - 1);
      return 0;
    }
  }
}