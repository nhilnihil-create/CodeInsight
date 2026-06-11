#include <iostream>
#include <set>
using namespace std;

int main () {
  int a, b, c;
  cin >> a >> b >> c;
  int sum = a+b+c;
  int nmax = max({a,b,c});
  
  cout << ( nmax == (sum-nmax) ? "Yes" : "No") << endl;
}