#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

constexpr ll Modulus = 1e9 + 7;

class modint {
    using u64 = std::uint_fast64_t;

public:
    u64 a;
    constexpr modint(const u64 x = 0) noexcept : a(x% Modulus) {}
    constexpr u64& value() noexcept { return a; }
    constexpr const u64& value() const noexcept { return a; }
    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint& operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr modint& operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint& operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
};



struct PartialArrayDp {
    string s;
    int n;
    vector<vector<int>> next_;
    vector<ll> dp_;

    PartialArrayDp(string s) {
        this->s = s;
        n = s.size();
        next_ = calcNext(s);
    }

    void solve() {
        //dp[i]...i番目の文字を必ず使う、i番目までの部分列の総数
        //総数...Σdp
        dp_ = vector<ll>(n + 1, 0);
        dp_[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (next_[i][j] >= n) continue;
                dp_[next_[i][j] + 1] += dp_[i];
            }
        }
    }

private:
    static vector<vector<int> > calcNext(const string& S) {
        int n = (int)S.size();
        vector<vector<int> > res(n + 1, vector<int>(26, n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) res[i][j] = res[i + 1][j];
            res[i][S[i] - 'a'] = i;
        }
        return res;
    }
};



int main() {
    string a;
    cin >> a;
    int n = a.size();
    vector<string> dp(26);
    rep(i, 26) {
        if (a[n - 1] != i + 'a') {
            dp[i] = (char)(i + 'a');
        }
        else {
            dp[i] += (char)(i + 'a');
            dp[i] += 'a';
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        rep(j, 26) {
            if (a[i] != j + 'a') {
            }
            else {
                //先頭文字がjであった場合、
                ll m = INF;
                int id = 0;
                rep(j, 26) {
                    if (m > dp[j].size()) {
                        m = dp[j].size();
                        id = j;
                    }
                }
                string t;
                t += (char)(j + 'a');
                t += dp[id];
                dp[j] = t;
            }
        }
    }
    ll m = INF;
    int id = 0;
    rep(i, 26) {
        if (m > dp[i].size()) {
            m = dp[i].size();
            id = i;
        }
    }
    cout << dp[id] << endl;
    return 0;
}
