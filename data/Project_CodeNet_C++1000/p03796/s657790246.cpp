#include <bits/stdc++.h>
using namespace std;

int main() {
  long long num;
  long long kekka = 1;
  
  cin >> num;
  
  for(int i = 1; i <= num; i++){
    kekka *= i;
    kekka %= 1000000007;
  }
  
  cout << kekka;
}
