#include <bits/stdc++.h>
using namespace std;
     
int main() {
  long long x;
  cin >> x;
  long long pro = x / 11;
  if(x % 11 <= 6 && x % 11 != 0){
    cout << pro * 2 + 1 << endl;
    return 0;
  }
  if(x % 11 == 0){
    cout << pro * 2 << endl;
    return 0;
  }
    cout << pro * 2 + 2 << endl;
}