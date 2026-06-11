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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , a[100000] = {} , b , x = 0 , y = 0;
    cin >> n;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> b;
        a[b]++;
    }
    for ( int i = 0 ; i < 100000 ; i++ ) {
        if ( a[i] % 2 == 1 ) x++;
        else if ( a[i] % 2 == 0 && a[i] > 0 ) y++;
    }
    if ( y % 2 == 0 ) cout << x + y;
    else cout << x + y - 1;
}
