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
    ll t[n] , a[n];
    cin >> t[0] >> a[0];
    ll x = t[0] , y = a[0];
    for (int i = 1; i < n ; i++) {
        cin >> t[i] >> a[i];
        ll b = x , c = y;
        x = t[i] * max( ( b - 1) / t[i] + 1 , ( c - 1 ) / a[i] + 1 );
        y = a[i] * max( ( b - 1) / t[i] + 1 , ( c - 1 ) / a[i] + 1 );
    }
    cout << x + y;
}
