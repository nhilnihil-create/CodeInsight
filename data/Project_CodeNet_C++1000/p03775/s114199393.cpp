#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  long long N;
  cin >> N;
  long long digit, digit2;
  digit = (long long)log10(N) + 1;
  for(long long i = 1; i * i <= N; i++){
    if(N % i == 0){
      digit2 = (long long)log10(N / i) + 1;
      digit = min(digit, digit2);
    }
  }
  cout << digit << endl;
}