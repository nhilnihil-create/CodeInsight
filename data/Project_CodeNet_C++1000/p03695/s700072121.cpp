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
    int n;
    cin >> n;
    int a , b[9] = {} , x = 0;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> a;
        if( a >= 3200 ) b[8]++;
        else b[a / 400] = 1;
    }
    for ( int i = 0 ; i < 8 ; i++ ) x += b[i];
    cout << max( x , 1 ) << ' ' << x + b[8];
}
