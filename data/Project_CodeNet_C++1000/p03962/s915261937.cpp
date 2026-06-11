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
          

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a[3] , b , c = 1;
    cin >> a[0] >> a[1] >> a[2];
    if ( a[0] == a[1] && a[0] == a[2] ) cout << 1;
    if ( a[0] == a[1] && a[0] != a[2] ) cout << 2;
    if ( a[0] == a[2] && a[0] != a[1] ) cout << 2;
    if ( a[1] == a[2] && a[1] != a[0] ) cout << 2;
    if ( a[0] != a[1] && a[1] != a[2] && a[0] != a[2] ) cout << 3;
}
