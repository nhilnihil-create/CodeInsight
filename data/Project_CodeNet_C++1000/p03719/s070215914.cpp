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
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
  	int a , b , c;
    cin >> a >> b >> c;
  	if ( c >= a && c <= b ) cout << "Yes";
    else cout << "No";
}