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
    ll a[n][n] , b[m][m];
    for (int i = 0 ; i < n ; i++ ) cin >> a[i][0] >> a[i][1];
    for (int i = 0 ; i < m ; i++ ) cin >> b[i][0] >> b[i][1];
    for (int i = 0 ; i < n ; i++ ) {
        ll x = abs( a[i][0] - b[0][0] ) + abs( a[i][1] - b[0][1] ) , y = 1;
        for (int j = 0 ; j < m - 1 ; j++ ) {
            if ( x > abs( a[i][0] - b[j + 1][0] ) + abs( a[i][1] - b[j + 1][1] ) ) {
                y = j + 2;
                x = abs( a[i][0] - b[j + 1][0] ) + abs( a[i][1] - b[j + 1][1] );
            }
        }
        cout << y << endl;
    }
}