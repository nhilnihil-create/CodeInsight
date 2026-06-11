#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <utility>
using namespace std;

int main(){
  unsigned long long n;
  cin >> n;
  unsigned long long c = n / 11;
  unsigned long long r = n % 11;
  if(r < 7 && r != 0){cout << c * 2 + 1 << endl;}
  else if(r == 0){cout << c * 2 << endl;}
  else{cout << c * 2 + 2 << endl;}
}