#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

ll GCD(ll a, ll b){
    if(b == 0) return a;
    else return GCD(b, a % b);
}

ll LCM(ll a, ll b){
    ll gcd = GCD(a, b);
    ll lcm = (a / gcd) * b;
    return lcm;
}

int main(){
    int N;
    cin >> N;
    vector<ll> T(N);
    rep(i, N) cin >> T[i];
    ll lcm = 1;
    rep(i, N){
        lcm = LCM(lcm, T[i]);
    }
    cout << lcm << endl;
    return 0;
}