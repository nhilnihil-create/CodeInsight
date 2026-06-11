#include <iostream>

#define MOD (1000000007UL)

using namespace std;
int main(){
  long n;
  cin >> n;
  long power = 1;
  for(long i = 1; i < n+1; i++){
    power *= i;
    if(power > MOD) {
      power = power%MOD;
    }
  }

  cout << power << endl;
  return 0;
}

