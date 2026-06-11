#include <bits/stdc++.h>
using namespace std;

namespace MMNMM {
    template<typename T, T MOD>
    class modint {
        using value_type = T;
    public:
        value_type val;

        static value_type e() noexcept {
            return static_cast<value_type>(1);
        }

        static value_type z() noexcept {
            return static_cast<value_type>(0);
        }

        modint(const value_type &_val = 0) : val(_val) {}

        const modint operator++(int) {
            modint ret = *this;
            if (val != MOD - e())++val;
            else val = z();
            return ret;
        }

        const modint operator--(int) {
            modint ret = *this;
            if (val != z())--val;
            else val = MOD - e();
            return ret;
        }

        modint &operator++() {
            if (val != MOD - e())++val;
            else val = z();
            return *this;
        }

        modint &operator--() {
            if (val != z())--val;
            else val = MOD - e();
            return *this;
        }

        modint operator-() const {
            return modint(val ? MOD - val : 0);
        }

        modint operator+() const {
            return modint(val);
        }

        modint &operator+=(modint &rhs) noexcept {
            this->val += rhs.val;
            this->val -= (this->val >= MOD) * MOD;
            return *this;
        }

        modint &operator-=(modint &rhs) noexcept {
            this->val += MOD - rhs.val;
            this->val -= (this->val >= MOD) * MOD;
            return *this;
        }

        modint &operator*=(modint &rhs) noexcept {
            this->val *= rhs.val;
            this->val %= MOD;
            return *this;
        }
    };

    template<typename T, T MOD>
    modint<T, MOD> operator+(const modint<T, MOD> &a, const modint<T, MOD> &b) {
        auto t = a.val + b.val;
        return modint<T, MOD>(t - (t >= MOD) * MOD);
    }

    template<typename T, T MOD>
    modint<T, MOD> operator-(const modint<T, MOD> &a, const modint<T, MOD> &b) {
        return a + (-b);
    }

    template<typename T, T MOD>
    modint<T, MOD> operator*(const modint<T, MOD> &a, const modint<T, MOD> &b) {
        return modint<T, MOD>(a.val * b.val % MOD);
    }

    template<typename T, T MOD>
    ostream &operator<<(ostream &os, const modint<T, MOD> &mi) {
        os << mi.val;
        return os;
    }

    template<typename T, T MOD>
    istream &operator>>(istream &is, modint<T, MOD> &mi) {
        is >> mi.val;
        return is;
    }

    template<typename Field, size_t n>
    class square_matrix {
        using value_type = vector<vector<Field>>;
    public:
        value_type val;

        explicit square_matrix(const value_type &_val) : val(_val) {}

        static value_type e() noexcept {
            value_type ret(n, vector<Field>(n, Field::z()));
            for (size_t i = 0; i < n; ++i)ret[i][i] = Field::e();
            return ret;
        }

        static value_type z() noexcept {
            value_type ret(n, vector<Field>(n, Field::z()));
            return ret;
        }

        static value_type transpose(const value_type &a) noexcept {
            value_type ret(z());
            for (unsigned long i = 0; i != n; ++i)
                for (unsigned long j = 0; j != n; ++j)
                    ret[i][j] = a[j][i];
            return ret;
        }

        square_matrix operator-() const {
            auto ret = this->val;
            for (auto &i : ret) {
                for (auto &j : i)j = -j;
            }
            return square_matrix(ret);
        }

        square_matrix &operator*=(const square_matrix &rhs) noexcept {
            value_type ret(n, vector<Field>(n, Field::z()));
            for(unsigned long i = 0; i != n; ++i)
                for(unsigned long j = 0; j != n; ++j)
                    for(unsigned long k = 0; k != n; ++k)
                        ret[i][j] = ret[i][j] + val[i][k] * rhs.val[k][j];
            this->val = ret;
            return *this;
        }
    };
}

template<typename Monoid>
Monoid pow(Monoid a, size_t n){
    Monoid ret{Monoid::e()};
    while(n){
        if(n & 1)ret *= a;
        a *= a;
        n >>= 1;
    }
    return ret;
}

int main(){
    constexpr long MOD = 1000000007;
    using modint = MMNMM::modint<unsigned long, MOD>;
    modint N;
    cin >> N;
    MMNMM::square_matrix<modint, 4> a({{1, 1, 0, 0}, {0, 0, 1, 0}, {1, 0, 1, MOD - 1}, {0, 0, 0, 1}});
    auto t = pow(a, N.val);
    cout << t.val[0][0] + t.val[0][3] + (t.val[0][2] * N + t.val[0][1]) * (N - modint(1)) << endl;
    return 0;
}