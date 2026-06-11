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

    ll x,y,X,Y;
    cin >> x >> y >> X >> Y;
    ll H = Y-y;
    bool isUp = true;
    if(H<0) isUp = false;
    ll W = X-x;
    bool isRight = true;
    if(W<0) isRight = false;
    string out = "";
    rep(i,H){
        if(isUp) out += "U";
        else out += "D";
    }
    rep(i,W){
        if(isRight) out += "R";
        else out += "L";
    }
    rep(i,H){
        if(isUp) out += "D";
        else out += "U";
    }
    rep(i,W){
        if(isRight) out += "L";
        else out += "R";
    }
    if(isRight) out += "L";
    else out += "R";
    rep(i,H+1){
        if(isUp) out += "U";
        else out += "D";
    }
    rep(i,W+1){
        if(isRight) out += "R";
        else out += "L";
    }
    if(isUp) out += "D";
    else out += "U";
    if(isRight) out += "R";
    else out += "L";
    rep(i,H+1){
        if(isUp) out += "D";
        else out += "U";
    }
    rep(i,W+1){
        if(isRight) out += "L";
        else out += "R";
    }
    if(isUp) out += "U";
    else out += "D";
    cout << out << endl;
    return 0;
}
