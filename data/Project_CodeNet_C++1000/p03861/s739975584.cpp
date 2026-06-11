#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a,b,x;
  cin >> a >> b >> x;
  long long A;
  if (a > 0){
    A = b/x - (a-1)/x;
  }
  else {
    A = b/x + 1;
  }
  cout << A << endl;
}