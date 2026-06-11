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
    long long int n , m , c = 0;
    cin >> n >> m;
    if ( m >= n * 2 ) {
        c += n;
        m -= n * 2;
        c += m / 4;
    } else {
        c += m / 2;
    }
    cout << c;
}