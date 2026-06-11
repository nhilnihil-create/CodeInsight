#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, long long> pdl;

const long double pi = 3.141592653589793;

#define debug(x) cerr << #x << " = " << (x) << endl;
#define rep(i, n) for(int i = 0;i < n;i++)
#define pb push_back
#define mp make_pair
#define mod 1000000007

ll f(ll n) {
    if(n == 0 || n == 1) return 1;
    return n*f(n-1);
}

void smoothing(vector<ll> &C) {
    C[0] = 1;
    for(int i = 1;i < C.size();i++) {
        if(C[i-1] + 1 < C[i]) {
            C[i] = C[i-1] + 2;
        }
    }
}

int main() {

    //freopen("input07.txt","r",stdin);
    //freopen("output_file_name.txt","w",stdout);
    ll n;
    cin>>n;
    vector<ll> B(n);
    vector<ll> K(n);
    vector<ll> A(n);
    rep(i, n) cin>>B[i];

    // play with B
    smoothing(B);

    // fill K
    K[0] = 0;
    ll toremove = 0;
    ll v = 3;

    for(int i = 1;i < B.size();i++) {
        if(B[i] < v) {toremove++;}
        else {v += 2;}
        K[i] = toremove;
    }

    A[0] = 1;
    for(int i = 1;i < A.size();i++) {
        A[i] = (A[i-1]*(i-K[i-1]+1))%mod;
    }

    cout<<A[n-1]<<endl;

    return 0;
}
