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

    ll N,A,B;
    cin >> N >> A >> B;
    ll X[N];
    rep(i,N) cin >> X[i];
    ll out = 0;
    rep(i,N-1){
        out += min((X[i+1]-X[i])*A,B);
    }
    cout << out << endl;
    return 0;
}
