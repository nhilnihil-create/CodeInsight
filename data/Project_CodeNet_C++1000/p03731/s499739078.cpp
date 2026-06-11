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
    int a , b;
    cin >> a >> b;
    int c[a] , x = b;
    for ( int i = 0 ; i < a ; i++ ) {
        cin >> c[i];
    }
    for( int i = 0 ; i < a - 1 ; i++ ) {
       if ( c[i + 1] - c[i] >= b ) x += b;
       else x += c[i + 1] - c[i];
    }
    cout << x;
}
