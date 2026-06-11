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
    ll mod = 1000000007;
    ll N;
    cin >> N;
    ll A[N+1];
    rep(i,N+1) A[i] = 0;
    for(ll i=2;i<=N;i++){
        ll I = i;
        while(I>1){
            if((ll)sqrt(I)==1){
                A[I]++;
                I /= I;
                break;
            }
            for(ll j=2;j<=sqrt(I);j++){
                if(I%j==0){
                    if(j!=1) A[j]++;
                    I /= j;
                    break;
                }
                if(j==(ll)sqrt(I)){
                    A[I]++;
                    I /= I;
                    break;
                }
            }
        }
    }
    ll out = 1;
    rep(i,N+1) out = (out * (A[i]+1)) % mod;
    cout << out << endl;
    return 0;
}
