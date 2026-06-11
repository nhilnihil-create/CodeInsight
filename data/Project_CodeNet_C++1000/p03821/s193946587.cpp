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

    ll N;
    cin >> N;
    ll A[N];
    ll B[N];
    rep(i,N) cin >> A[i] >> B[i];
    ll out = 0;
    rep(i,N){
        A[N-1-i] += out;
        ll C = A[N-1-i]%B[N-1-i];
        if(C==0) C = B[N-1-i];
        out += B[N-1-i]-C;
    }
    cout << out << endl;
    return 0;
}
