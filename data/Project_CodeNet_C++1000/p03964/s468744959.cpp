#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

const ll MAX = 1e18;

int main() {
    ll N; cin >> N;
    ll tmpT, tmpA; cin >> tmpT >> tmpA;
    ll T, A;
    ll mid, ok, ng, nowT, nowA;
    for (ll i = 1; i < N; i++) {
        cin >> T >> A;
        ng = 0; ok = MAX;
        while(abs(ok-ng) > 1) {
            mid = (ok+ng)/2;
            nowT = (tmpT%mid? tmpT/mid+1:tmpT/mid);
            nowA = (tmpA%mid? tmpA/mid+1:tmpA/mid);
            if (T < nowT || A < nowA) ng = mid;
            else ok = mid;
        }
        tmpT = ok*T;
        tmpA = ok*A;
        //cout << tmpT + tmpA << endl;
    }
    cout << tmpA + tmpT << endl;
}
