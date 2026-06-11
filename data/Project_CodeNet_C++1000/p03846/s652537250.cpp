#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int mod = 1e9+7;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N){
        int a; cin >> a;
        A[a]++;
    }
    ll ans = 1;
    bool ok = true;
    if(N%2 == 1){
        for (int i = 0; i < N; i+=2){
            if(i == 0){
                if(A[i] != 1)ok = false;
            } else {
                if(A[i] != 2){
                    ok = false;
                } else {
                    ans *= 2;
                    ans %= mod;
                }
            }
        }
    } else {
        for (int i = 1; i < N; i+=2){
            if(A[i] != 2){
                ok = false;
            } else {
                ans *= 2;
                ans %= mod;
            }
        }
    }

    if(ok){
        cout << ans << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}