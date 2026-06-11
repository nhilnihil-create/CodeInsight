#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;
typedef double d;
typedef int i;
 
int main() {
  string a , b;
  cin >> a >> b;
  for ( int i = 0 ; i < b.length() ; i++ ) cout << a[i] << b[i];
  if ( a.length() > b.length() ) cout << a[a.length() - 1];
}