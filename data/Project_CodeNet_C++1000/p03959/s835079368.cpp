#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

const int MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> T(N), A(N);
    Rep (i, N) {
        cin >> T[i];
    }
    Rep (i, N) {
        cin >> A[i];
    }

    vector<ll> ttmp(N), atmp(N), mt(N);
    vector<bool> t(N, false), a(N, false), m(N, false);

    ll tmp = 0, ans = 1;
    Rep (i, N) {
        if (T[i] > tmp) {
            ttmp[i] = T[i];
            t[i] = true;
            tmp = T[i];
        } else if (T[i] == tmp) {
            ttmp[i] = T[i];
        }
    }
    tmp = 0;
    for (ll i = N - 1; i >= 0; i--) {
        if (A[i] > tmp) {
            atmp[i] = A[i];
            a[i] = true;
            tmp = A[i];
        } else if (A[i] == tmp) {
            atmp[i] = A[i];
        }
    }

    Rep (i, N) {
        if (!t[i] && !a[i]) mt[i] = min(ttmp[i], atmp[i]);
        else if (t[i] && a[i]) {
            if (ttmp[i] == atmp[i]) {
                mt[i] = 1;
            }
            else mt[i] = 0;
        }
        else if (t[i] && !a[i]) {
            if (ttmp[i] <= atmp[i]) {
                mt[i] = 1;
            } else mt[i] = 0;
        } else if (!t[i] && a[i]) {
            if (atmp[i] <= ttmp[i]) mt[i] = 1;
            else mt[i] = 0;
        }
    }

    Rep (i, N) {
        ans *= mt[i];
        ans %= MOD;
    }

    cout << ans << "\n";
}