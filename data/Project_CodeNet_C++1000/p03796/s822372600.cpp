#include<iostream>
#include<cmath>
using namespace std;

int main() {
  int i, N;
  long long int sum=1;
  
  cin >> N;
  
  for(i=1; i<=N; i++) {
    sum *= i;
    sum %= (long long)(pow(10,9)+7);
    //cout << sum << endl;
  }
  
  cout << sum << endl;

  return 0;
}
