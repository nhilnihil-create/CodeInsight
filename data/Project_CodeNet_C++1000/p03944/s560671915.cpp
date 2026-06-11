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

    ll W,H,N;
    cin >> W >> H >> N;
    ll w = 0;
    ll h = 0;
    rep(i,N){
        ll x,y,a;
        cin >> x >> y >> a;
        if(a==1&&w<x) w = x;
        else if(a==2&&W>x) W = x;
        else if(a==3&&h<y) h = y;
        else if(a==4&&H>y)H = y;
    }
    ll out = 0;
    if(H>h&&W>w) out = (H-h)*(W-w);
    cout << out << endl;
    return 0;
}
