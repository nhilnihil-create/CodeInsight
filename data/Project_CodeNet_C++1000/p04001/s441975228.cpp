#include <bits/stdc++.h>
using namespace std;

int64_t FormulaSum(int64_t Num){
  if(Num < 10){
    return Num;
  }
  
  int64_t sum = Num;
  int64_t exp2 = 1;
  int64_t exp10 = 1;
  while (Num / 10 >= exp10) {
    exp10 *= 10;
    sum += Num / exp10 * exp2;
    sum += FormulaSum(Num % exp10);
    exp2 *= 2;
  }

  return sum;
}

int main() {
  int64_t S;
  cin >> S;
  
  cout << FormulaSum(S) <<endl;
  
  return 0;
}
