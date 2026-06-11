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
    string s;
    cin >> s;
    for ( int i = (int)s.length() - 1 ; i > 0 ; i-- ) {
        if ( s.substr( 0 , i / 2 ) == s.substr( i / 2 , i / 2 ) && i % 2 == 0 ) {
            cout << i;
            return 0;
        }
    }
}

