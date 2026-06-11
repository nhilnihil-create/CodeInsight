#include<bits/stdc++.h>
using namespace std;
int main(){
  long long a, b, n; cin >> a >> b;
  if(a > b/2) n = b/2;
  else n = a+(b-2*a)/4;
  cout << n << "\n";
}