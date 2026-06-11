#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int a, b;
  cin >> a >> b;
  if(a*b<=0) {
      cout << "Zero" << endl;
  }
  else if(a>0) {
      cout << "Positive" << endl;
  }
  else if((b-a+1)%2==0) {
      cout << "Positive" << endl;
  }
  else if((b-a+1)%2!=0) {
      cout << "Negative" << endl;
  }
}