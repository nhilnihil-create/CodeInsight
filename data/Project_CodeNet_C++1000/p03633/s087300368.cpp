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
ll gcd( ll a , ll b )  {
    return b ? gcd( b , a % b ) : a;
}
ll lcm( ll a , ll b ) {
    return a / gcd( a , b ) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll a , b = 1;
    cin >> n;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> a;
        b = lcm( a , b );
    }
    cout << b;
}


