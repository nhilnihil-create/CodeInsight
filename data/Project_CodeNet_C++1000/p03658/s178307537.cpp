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
    int n , k , c = 0;
    cin >> n >> k;
    int l[n];
    for( int i = 0 ; i < n ; i++ ) cin >> l[i];
    sort( l , l + n );
    for( int i = n - 1 ; i >= n - k ; i-- ) c += l[i];
    cout << c;
}
