#include <cstdlib>
#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b){
  if(a%b == 0){
    return b;
  } else {
    return gcd(b, a%b);
  }
}

int main(){
  int n;
  cin >> n;
  unsigned long long t[n];
  for(int i = 0; i < n; i++){
    cin >> t[i];
  }
    
  unsigned long long sec = t[0];
  for(int i = 1; i < n; i++){
    unsigned long long tmp_gcd = gcd(sec, t[i]);
    if(sec % tmp_gcd == 0){
      sec = (sec/tmp_gcd)*t[i];
    } else {
      sec = (sec*t[i]/tmp_gcd);
    }
  }
  cout << sec << endl;

  return 0;
}
