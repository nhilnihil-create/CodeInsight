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
using Graph = vector<vector<ll>>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {
    ll N,P;
    cin >> N >> P;
    ll A[N];
    bool existOdd = false;
    rep(i,N){
        cin >> A[i];
        if(A[i]%2==1) existOdd = true;
    }
    ll out = 0;
    if(existOdd) out = pow(2,N-1);
    else{
        if(P==0) out = pow(2,N);
        else out = 0;
    }
    cout << out << endl;
    return 0;
}
