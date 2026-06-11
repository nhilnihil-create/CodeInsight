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
    int l[n] , r[n] , c = 0;
    for( int i = 0 ; i < n ; i++ ) {
        cin >> l[i] >> r[i];
        c += r[i] - l[i] + 1;
    }
    cout << c;
}



