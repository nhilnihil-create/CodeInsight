#include <iostream>

using namespace std;

int main(void){
  long long int n, i, sum = 0, yo;
  cin >> n;
  sum = (n / 11) * 2;
  yo = n % 11;
  if(yo > 6){
    sum = sum + 2;
  }else if(yo > 0){
    sum = sum + 1;
  }
  cout << sum << endl;
  
  return 0;
}