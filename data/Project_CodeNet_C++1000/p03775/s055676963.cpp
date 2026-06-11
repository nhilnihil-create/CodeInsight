#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define REP(i, n) for (long long i = 0; i < (n); i++)
const ll INF = 1LL << 60;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
};
ll modpow(ll m, ll n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        ll t = modpow(m, n / 2);
        return t * t;
    } else {
        return modpow(m, n - 1) * m;
    }
}
void printInBase(int x, int y) {
    if (x < y) {
        cout << x;
        return;
    }
    int rem = x % y;
    printInBase(x / y, y);
    cout << rem;
}
map<ll, ll> cnt;
void primeFactors(long long n) {
    while (n % 2 == 0) {
        cnt[2]++;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            cnt[i]++;
            n = n / i;
        }
    }
    if (n > 2) {
        cnt[n]++;
    }
}

int main() {
    ll n;
    cin >> n;
    for (int i = sqrt(n); i > 0; i--) {
        if (n % i == 0) {
            string s;
            s = to_string(n / i);
            cout << s.size() << endl;
            break;
        }
    }
}