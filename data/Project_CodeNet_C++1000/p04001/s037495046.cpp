#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
#define REP(i, n) for (long long i = 0; i < (n); i++)

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t;
    } else {
        return modpow(m, n - 1) * m;
    }
}
typedef long long ll;
typedef pair<ll, ll> P;
map<long long, long long> cnt;
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
bool bitcheck(int x, int y) { return (x >> y) & 1; }
signed main() {
    string s;
    cin >> s;
    ll n = s.size();
    ll sum = 0;
    REP(i, 1 << (n - 1)) {
        string t;
        REP(j, n) {
            t.push_back(s[j]);
            if (j == n - 1 || bitcheck(i, j)) {
                //cout << t << endl;
                sum += stol(t);
                t = "";
            }
        }
    }
    cout << sum << endl;
}