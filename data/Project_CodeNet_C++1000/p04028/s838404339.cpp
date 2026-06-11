#include "bits/stdc++.h"
using namespace std;
typedef long long li;

const li mod = 1e9 + 7;


template <long long mod>
struct modint {
    long long x;

    modint<mod>(): x(0LL) {}
    modint<mod>(const long long _data) {
        if (_data < 0) {
            x = (_data % mod + mod) % mod;
        } else if (_data >= mod) {
            x = _data % mod;
        } else {
            x = _data;
        }
    }

    bool operator==(const modint<mod>& op) const {
        return x == op.x;
    }

    bool operator!=(const modint<mod>& op) const {
        return !((*this) == op);
    }

    modint<mod> operator-() const {
        if (x == 0) {
            return modint(0);
        }
        return modint(mod - x);
    }

    modint<mod> operator+(const modint<mod>& op) const {
        const long long newdata = x + op.x;
        if (newdata >= mod) {
            return modint<mod>(newdata - mod);
        } else {
            return modint<mod>(newdata);
        }
    }

    modint<mod> operator-(const modint<mod>& op) const {
        return *this + (-op);
    }

    modint<mod> operator*(const modint<mod>& op) const {
        return modint<mod>(x * op.x % mod);
    }

    modint<mod> pow(const long long n) const {
        if (n == 0) {
            return modint<mod>(1);
        }
        modint<mod> sq = pow(n / 2);
        if (n & 1) {
            return (*this) * sq * sq;
        } else {
            return sq * sq;
        }
    }

    modint<mod> inverse() const {
        return pow(mod - 2);
    }

    modint<mod> operator/(const modint<mod>& op) const {
        return (*this) * op.inverse();
    }

    friend modint<mod> operator/(const long long dividend, const modint<mod>& divisor) {
        return modint<mod>(dividend) / divisor;
    }

    static modint<mod> factorial(const long long n) {
        static std::vector<modint<mod>> cache(1, 1);

        while (cache.size() <= n) {
            modint<mod> next = cache.back() * cache.size();
            cache.push_back(next);
        }
        return cache[n];
    }

    static modint<mod> combination(const long long n, const long long k) {
        if (k < 0 || n < k) {
            return modint<mod>(0);
        }

        if (n < 1e6) {
            return factorial(n) / (factorial(k) * factorial(n - k));
        }

        modint<mod> ret(1);
        for (int i = 1; i <= k; ++i) {
            ret = ret * modint<mod>(n - i + 1) / modint<mod>(i);
        }
        return ret;
    }
};

typedef modint<1000000007> mint;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    li n;
    cin >> n;
    string s;
    cin >> s;

    const li m = s.size();

    const li dp_size = 10005;
    mint dist_dp[2][dp_size], length_dp[2][dp_size];
    dist_dp[0][m] = 1;
    length_dp[0][0] = 1;

    int next = 1;
    for (int i = 0; i < n; ++i) {
        for (int fr = 0; fr < dp_size; ++fr) {
            dist_dp[next][fr] = 0;
            length_dp[next][fr] = 0;
        }
        for (int fr = 0; fr < dp_size; ++fr) {
            if (fr == 0) {
                length_dp[next][fr] = length_dp[next][fr] + length_dp[1 - next][fr];
            } else {
                length_dp[next][fr - 1] = length_dp[next][fr - 1] + length_dp[1 - next][fr];
            }
            length_dp[next][fr + 1] = length_dp[next][fr + 1] + length_dp[1 - next][fr] * 2;

            if (fr == 0) {
                dist_dp[next][fr + 1] = dist_dp[next][fr + 1] + dist_dp[1 - next][fr] * 3;
            } else {
                mint empty, non_empty;
                if (fr == m) {
                    empty = length_dp[1 - next][0];
                    non_empty = dist_dp[1 - next][fr] - empty;
                } else {
                    empty = 0;
                    non_empty = dist_dp[1 - next][fr];
                }
                dist_dp[next][fr] = dist_dp[next][fr] + empty;
                dist_dp[next][fr - 1] = dist_dp[next][fr - 1] + empty + non_empty;
                dist_dp[next][fr + 1] = dist_dp[next][fr + 1] + empty + non_empty * 2;
            }

        }
        next = 1 - next;
    }

    cout << dist_dp[1 - next][0].x << endl;

    return 0;
}