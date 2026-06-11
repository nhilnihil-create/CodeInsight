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
    long long int n , a , b , c = 0;
    cin >> n >> a >> b;
    long long int x[n];
    for ( int i = 0 ; i < n ; i++ ) cin >> x[i];
    for ( int i = 0 ; i < n - 1 ; i++ ) {
        if ( ( x[i + 1] - x[i] ) * a < b ) c += ( x[i + 1] - x[i] ) * a;
        else c += b;
    }
    cout << c;
}
