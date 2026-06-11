#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<long long>;
using pll = pair<long long, long long>;
#define rep(i,n) for(long long i(0);(i)<(n);(i)++)


ll gcd (ll a, ll b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

ll myrec(ll N, ll X){
    if(X == 0) 
        return 0;
    if(X == 1)
        return 3*(N-1);
    if(2*X == N)
        return 3*X;
    if(2*X < N){
        ll Nnew = N%X + X;
        ll d = myrec(Nnew, X);
        return d + 3*(N-Nnew);
    }
    if(2*X > N){ 
        ll Nnew = N-X + X%(N-X);
        ll d = myrec(Nnew, X%(N-X));
        return d + 3*(N-Nnew);
    }
}

void solve(long long N, long long X){
    ll k = gcd(N, X);
    ll ans = myrec(N/k, X/k);
    cout << ans*k << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long X;
    scanf("%lld",&X);
    solve(N, X);
    return 0;
}
