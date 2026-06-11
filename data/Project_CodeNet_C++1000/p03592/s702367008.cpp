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
    // 入力
    ll N,M,K;
    cin >> N >> M >> K;
    string out = "No";
    ll S = 0;
    rep(i,N+1){
        rep(j,M+1){
            S = i*M + j*N - i*j*2;
            if(S==K||N*M-S==K) {
                out = "Yes";
                break;
            }
        }
    }
    cout << out << endl;
    return 0;
}
