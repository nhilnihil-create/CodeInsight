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
    int n;
    cin >> n;
    int a , b = 0 , c = 0 , d = 0;
    for( int i = 0 ; i < n ; i++ ) {
        cin >> a;
        if( a % 4 == 0 ) b++;
        else if( a % 4 == 2 ) c++;
        else d++;
    }
    if( d <= b ) cout << "Yes";
    else if( c == 0 && d <= b + 1 ) cout << "Yes";
    else cout << "No";
}


