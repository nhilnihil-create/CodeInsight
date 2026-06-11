#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

struct Sieve {
    int n;
    vector<int> f, primes;
    Sieve(int n = 1) :n(n), f(n + 1) {
        f[0] = f[1] = -1;
        for (ll i = 2; i <= n; i++) {
            if (f[i]) {
                continue;
            }
            primes.push_back(i);
            f[i] = i;
            for (ll j = i * i; j <= n; j += i) {
                if (!f[j]) {
                    f[j] = i;
                }
            }
        }
    }

    bool isPrime(int x) {
        return f[x] == x;
    }

    vector<int> factorList(int x) {
        vector<int> res;
        while (x != 1) {
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }

    vector<P> factor(int x) {
        vector<int> fl = factorList(x);
        if (fl.size() == 0) {
            return {};
        }
        vector<P> res(1, P(fl[0], 0));
        for (int p : fl) {
            if (res.back().first == p) {
                res.back().second++;
            }
            else {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    Sieve sieve(n);
    map<int, ll> mp;
    for(int i = 2; i <= n; i++){
        vector<P> f = sieve.factor(i);
        for(P p : f){
            mp[p.first] += p.second;
        }
    }

    ll ans = 1;
    int mod = 1000000007;
    for(auto itr = mp.begin(); itr != mp.end(); itr++){
        ans *= itr->second + 1;
        ans %= mod;
    }
    cout << ans << endl;
}