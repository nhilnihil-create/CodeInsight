#include <iostream>
using namespace std;
const int MOD = 1e9+7;

int main(){
  int n ; cin >> n;
  long long power = 1;
  for(int i = 1; i <= n; ++i){
    power *= i;
    power %= MOD;
  }
  cout << power << endl;
  return 0; 
}
