#include <bits/stdc++.h>
using namespace std;

int main() {
  long long num, a, b;
  long long Max,Min,kekka;
  
  cin >> num >> a >> b;
  
  if(num == 1 && a == b){
    cout << 1;
    return 0;
  }
  
  if(num == 1 && a != b){
    cout << 0;
    return 0;
  }
  
  if(a > b){
    cout << 0;
    return 0;
  }
  
  Max = a + (num-1) * b;
  Min = b + (num-1) * a;
  kekka = Max - Min + 1;
  
  cout << kekka;
}
