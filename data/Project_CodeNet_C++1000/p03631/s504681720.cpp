#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;

  int a=n/100;
  int b=n/10-a*10;
  int c=n%10;

  if (n==100*c+10*b+a) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
