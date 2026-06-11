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
    int n, tmp;
    cin >> n;
    int a[100000] = {0};
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> tmp;
        if ( tmp > 0 ) {
            a[tmp - 1]++;
        }
        a[tmp]++;
        a[tmp + 1]++;
    }
    int c = 0;
    for ( int i = 0 ; i < 100000 ; i++ ) {
        c = max( a[i] , c );
    }
    cout << c;
}



