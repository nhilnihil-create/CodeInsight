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

    ll N,M;
    cin >> N >> M;
    string A[N];
    rep(i,N) cin >> A[i];
    string B[M];
    rep(i,M) cin >> B[i];
    string out = "No";
    rep(i,N-M+1){
        rep(j,N-M+1){
            ll cnt = 0;
            rep(k,M){
                rep(l,M){
                    if(A[i+k][j+l]==B[k][l]) cnt++;
                    else break;
                }
            }
            if(cnt==M*M){
                out = "Yes";
                break;
            }
        }
    }
    cout << out << endl;
    return 0;
}
