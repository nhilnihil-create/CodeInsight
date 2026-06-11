#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const float pi = 3.1415926535;
unsigned GetDigit(unsigned num){
    return to_string(num).length();
}

int main() {
  int a,b;
  cin >> a >> b;
  
  if (a<=0 && b>=0) cout << "Zero" << endl;
  else if (b<0) {
    if ((b-a)%2==1) cout << "Positive" << endl;
    else cout << "Negative" << endl;
  }
  else if (a>0) cout << "Positive" << endl;
}