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

    ll N,C,K;
    cin >> N >> C >> K;
    ll T[N];
    rep(i,N){
        cin >> T[i];
    }
    sort(T,T+N);
    ll out = 0;
    ll start = 0;
    while(start<N){
        ll cnt = 0;
        rep(i,C){
            if(T[start+i]>T[start]+K||start+i==N) break;
            cnt = i;
        }
        start += cnt+1;
        out++;
    }
    cout << out << endl;
    return 0;
}
