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
  i w , a , b;
  cin >> w >> a >> b;
  if ( a < b && b - w - a > 0 ) cout << b - w - a;
  else if ( a < b && b - w - a <= 0 ) cout << 0;
  else if ( b < a && a - w - b > 0 ) cout <<  a - w - b;
  else cout << 0;
}