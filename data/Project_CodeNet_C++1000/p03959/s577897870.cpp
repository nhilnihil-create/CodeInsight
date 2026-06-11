#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll N;
ll T[105000];
ll A[105000];
ll maxi[105000];
ll B[105000];
const ll mod = 1e9+7;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> T[i];
    for(int i = 1; i <= N; i++) cin >> A[i];
    B[1] = T[1];
    B[N] = A[N];
    if(T[N] != A[1]) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 2; i <= N; i++) {
        if(T[i] == T[i-1]) continue;
        if(B[i] != 0 && B[i] != T[i]) {
            cout << 0 << endl;
            return 0;
        }
        B[i] = T[i];
    }
    for(int i = 1; i <= N - 1; i++) {
        if(A[i] == A[i+1]) continue;
        if(B[i] != 0 && B[i] != A[i]) {
            cout << 0 << endl;
            return 0;
        }
        B[i] = A[i];
    }
    for(int i = 1; i <= N; i++) {
        if(T[i] < B[i]) {
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = N; i >= 1; i--) {
        if(A[i] < B[i]) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1;
    for(int i = 1; i <= N; i++) {
        maxi[i] = 1e9;
        if(B[i] != 0) {
            continue;
            chmin(maxi[i], B[i]);
        }
        chmin(maxi[i], T[i]);
        chmin(maxi[i], A[i]);
        ans *= maxi[i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
