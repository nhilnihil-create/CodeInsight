#include<bits/stdc++.h>
using namespace std;

int main() {
  long double a, b;
  cin >> a >> b;
  
  if (a / b > 1)
    cout << "GREATER" << endl;
  if (a / b < 1)
    cout << "LESS" << endl;
  if (a / b == 1)
    cout << "EQUAL" << endl;
}