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
    int a[3] = {};
    cin >> a[0] >> a[1] >> a[2];
    sort( a , a + 3 );
    if ( a[2]  ==  a[0] + a[1] ) cout << "Yes\n";
    else cout << "No\n";
}

