#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x,c;
  cin >> x;
  c = x/11*2;
  if(x%11 != 0){
    if(x%11 < 7) c++;
    else c += 2;
  }
  cout << c << endl;
}
