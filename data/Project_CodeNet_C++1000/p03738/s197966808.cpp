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
    string a , b;
    cin >> a >> b;
    if ( a.length() > b.length() ) cout << "GREATER";
    else if ( a.length() < b.length() ) cout << "LESS";
    else {
        for ( int i = a.length() - 1 ; i >= 0 ; i-- ) {
            if ( a > b ) {
                cout << "GREATER";
                return 0;
            } else if ( a < b ) {
                cout << "LESS";
                return 0;
            }
        }
        cout << "EQUAL";
    }
}
