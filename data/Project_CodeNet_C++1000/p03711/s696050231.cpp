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
    int a[7] = {1 , 3 , 5 , 7 , 8 , 10 , 12} , b[4] = {4 , 6 , 9 , 11} , c , d , m = 0;
    cin >> c >> d;
    for ( int i = 0 ; i < 7 ; i++ ) {
        if ( c == a[i] || d == a[i] ) m++;
        if ( m == 2 ) {
            cout << "Yes";
            return 0;
        }
    }
    m = 0;
    for ( int i = 0 ; i < 4 ; i++ ) {
        if ( c == b[i] || d == b[i] ) m++;
        if ( m == 2 ) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
