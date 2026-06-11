#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define rep(i,n) for(int i = 0;i < n;i++)
#define NIL = -1;

ll gcd(long long a,long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    a / gcd(a,b) * b;
}
const int64_t INF = 1LL << 58;
const ll mod = 1e9 + 7;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<int64_t> a(n);
    
    for (int i = 0;i < n;i++) cin >> a[i];

    int64_t res = INF;

    for (int bit = 0;bit < (1 << n);bit++){
        if (__builtin_popcount(bit) < k) continue;

        int64_t cost = 0,last = 0;

        for (int i = 0;i < n;i++){
            if (bit & (1 << i)){
                last = max(last + 1,a[i]);
                cost += last - a[i];
            }
            else if (a[i] > last){
                cost = INF;
            }
        }

        res = min(res,cost);
    }       
    
    cout << res << endl;
}