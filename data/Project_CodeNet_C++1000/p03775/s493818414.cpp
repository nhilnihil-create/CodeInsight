#include <iostream>
using namespace std;

int Digits(long long n){
  int digits = 0;
  while(n>0){
    digits++;
    n /= 10;
  }
  return digits;
}

int main(){
  long long N;
  cin >> N;
  int ans = Digits(N);
  for(long long i=1; i*i<=N; i++){
    if(N%i == 0){
      ans = min(ans, Digits(N/i));
    }
  }
  cout << ans;
  return 0;
}