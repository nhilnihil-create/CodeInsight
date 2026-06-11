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
    int b[26] = {};
    string a;
    cin >> a;
    for ( int i = 0 ; i < a.length() ; i++ ) {
        b[a[i] - 'a']++;
        if( b[a[i] - 'a'] >= 2 ) {
            cout << "no";
            return 0;
        }
    }
    cout << "yes";
}
