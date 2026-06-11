#include <iostream>
using namespace std;
using ll = long long;

const int A=1e9+7;
int main(){
  int N;
  cin >> N;
  ll ans = 1;
  for(int i= 1; i<=N; i++){
    ans *= i;
    if(ans>=A){
      ans %= A;
    }
  }
  cout << ans;
  return 0;
}