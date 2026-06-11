#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;

typedef unsigned long long ll;

const long long MOD = 1000000000 + 7;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    ll n,x;
    cin >> n >> x;
    ll a[n];
    rep(i,n){
        cin >> a[i];
    }
    ll cnt = 0;
    rep(i,n-1){
        ll sum_candy = a[i] + a[i+1];
        if (sum_candy <= x) continue;
        ll byte = sum_candy - x;
        if ( a[i+1] > byte) a[i+1] -= byte;
        else {
            a[i] -= byte - a[i+1];
            a[i+1] = 0;
        }

        cnt += byte;
    }
    cout << cnt << endl;
    return 0;
}
