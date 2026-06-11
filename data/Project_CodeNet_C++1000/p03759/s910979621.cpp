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
  i a , b , c;
  cin >> a >> b >> c;
  if ( b - a == c - b ) cout << "YES";
  else cout << "NO";
}