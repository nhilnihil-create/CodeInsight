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

    string S;
    cin >> S;
    ll N = S.length();
    ll out = 0;
    rep(i,N){
        if(i>0&&S[i]!=S[i-1]) out++;
    }
    cout << out << endl;
    return 0;
}
