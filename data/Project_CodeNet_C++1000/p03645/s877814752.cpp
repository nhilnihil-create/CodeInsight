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
    ll L[N];
    rep(i,N) L[i] = 0;
    rep(i,M){
        ll a,b;
        cin >> a >> b;
        if(a==1) L[b-1]++;
        else if(b==N) L[a-1]++;
    }
    string out = "IMPOSSIBLE";
    rep(i,N){
        if(L[i]==2){
            out = "POSSIBLE";
            break;
        }
    }
    cout << out << endl;
    return 0;
}
