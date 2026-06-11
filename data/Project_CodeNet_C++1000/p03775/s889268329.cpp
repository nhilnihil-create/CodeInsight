#include <bits/stdc++.h>
using namespace std;

int digit(int64_t x)
{
  int digits = 0;
  while(x > 0){
    x /= 10;
    digits++;
  }
  
  return digits;
}

int main()
{
  int64_t n;
  cin >> n;
  
  int64_t fmin = digit(n),b = 0;
  int fn = 0;
  for(int64_t a = 1; a*a <= n; a++){
    if( (n % a) != 0){
      continue;
    }
    b = n / a;
   
    fn = max(digit(a),digit(b));
    if(fn < fmin){
      fmin = fn;
    }
  }//for
  
  cout << fmin << endl;
}
