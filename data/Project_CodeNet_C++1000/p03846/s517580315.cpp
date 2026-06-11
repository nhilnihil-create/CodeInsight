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
    ll A[100000] = {0};
    rep(i,N){
        ll a;
        cin >> a;
        A[a]++;
    }
    
    ll out = 0;
    bool isExist = true;
    ll tmp = 0;
    while(tmp<N){
        if(N%2==0&&tmp==0) tmp = 1;
        if(tmp==0){
            if(A[tmp]==1) tmp += 2;
            else{
                isExist = false;
                break;
            }
        }
        else{
            if(A[tmp]==2) tmp += 2;
            else{
                isExist = false;
                break;
            }
        }
    }
    
    if(isExist){
        out = 1;
        rep(i,N/2){
            out = (out*2)%mod;
        }
    }
    
    cout << out << endl;
    return 0;
}
