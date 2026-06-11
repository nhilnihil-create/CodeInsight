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

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll x,y;
    cin >> x >> y;
    ll out = abs(abs(x)-abs(y));
    if(x*y==0){
        if(x>y) out ++;
    }else if(x*y>0){
        if(x>y) out += 2;
    }else out++;
    cout << out << endl;
    return 0;
}
