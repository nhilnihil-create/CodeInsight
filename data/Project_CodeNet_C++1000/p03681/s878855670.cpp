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
    int n , m;
    cin >> n >> m;
    if( abs( n - m ) < 2 ) {
        if( n == m ) {
            ll a = 1;
            for( int i = 1 ; i <= n ; i++ ) {
                a = a * i % 1000000007;
            }
            cout << 2 * a * a % 1000000007;
        } else {
            ll a = 1 , b = 1;
            for( int i = 1 ; i <= n ; i++ ) {
                a = a * i % 1000000007;
            }
            for( int i = 1 ; i <= m ; i++ ) {
                b = b * i % 1000000007;
            }
            cout << a * b % 1000000007;
        }
    } else cout << 0;
}



