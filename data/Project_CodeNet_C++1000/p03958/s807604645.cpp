#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll K,T;
    cin >> K >> T;
    ll a[T];
    rep(i,T) cin >> a[i];
    sort(a,a+T);
    ll s = a[T-1]-1-(K-a[T-1]);
    ll out = 0;
    if(s>0) out = s;
    cout << out << endl;
    return 0;
}
