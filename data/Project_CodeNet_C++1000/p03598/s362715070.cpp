#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , k , c = 0;
    cin >> n >> k;
    int a[n];
    for( int i = 0 ; i < n ; i++ ) {
        cin >> a[i];
        if( abs( k - a[i] ) < a[i] ) c += abs( k - a[i] );
        else c += a[i];
    }
    cout << c * 2;
}
