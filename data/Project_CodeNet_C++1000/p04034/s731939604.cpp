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

    ll N,M;
    cin >> N >> M;
    ll A[N];
    rep(i,N) A[i] = 1;
    ll R[N];
    rep(i,N) R[i] = 0;
    R[0] = 1;
    rep(i,M){
        ll x,y;
        cin >> x >> y;
        if(A[x-1]>0) A[x-1]--;
        A[y-1]++;
        if(R[x-1]==1){
            R[y-1] = 1;
            if(A[x-1]==0) R[x-1] = 0;
        }
    }
    ll out = 0;
    rep(i,N) out += R[i];
    cout << out << endl;
    return 0;
}
