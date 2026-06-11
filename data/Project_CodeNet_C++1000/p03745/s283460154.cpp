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
    vector<ll> A;
    rep(i,N){
        ll a;
        cin >> a;
        if(i==0||A[A.size()-1]!=a) A.push_back(a);
    }
    ll out = 1;
    ll n = A.size();
    rep(i,n){
        if(i!=0&&i!=n-1){
            if((A[i]>A[i-1]&&A[i]>A[i+1])||(A[i]<A[i-1]&&A[i]<A[i+1])){
                out++;
                i++;
            }
        }
    }
    cout << out << endl;
    return 0;
}
