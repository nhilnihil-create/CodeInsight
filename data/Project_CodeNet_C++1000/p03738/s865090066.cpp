#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main(){
  string a, b;
  cin >> a >> b;
  if(a == b ) cout << "EQUAL" << endl;
  else if(a.size() > b.size()) cout << "GREATER" << endl;
  else if(a.size() < b.size() ) cout << "LESS" << endl;
  else if( a.size() == b.size()){
    if(a > b) cout << "GREATER" << endl;
    else cout << "LESS" << endl;
  }
}