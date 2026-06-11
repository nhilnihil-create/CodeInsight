#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long INF = 1LL << 60;
using Graph = vector<vector<int>>;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

inline int gcd(int a, int b) { return (a%b == 0) ? b : gcd(b, a%b); }
inline int fac(int n) { return (n==0) ? 1 : n * fac(n - 1); }

int main() {
    ll p[4];
    double p_unit[4];
    double lit[4] = {0.25, 0.5, 1.0, 2.0};
    for (int i = 0; i < 4; i++)
    {
        cin >> p[i];
        p_unit[i] = p[i] / lit[i];
    }
    ll n;
    cin >> n;

    ll total = 0;
    while (n > 0)
    {
        int max_lit_index = 0;
        for (int i = 0; i < 4; i++) {
            if (n >= lit[i])
                max_lit_index = i;
        }

        double min_lit_unit = 1000000000;
        int min_lit_index = 0;
        for (int i = 0; i < max_lit_index + 1; i++)
        {
            if (min_lit_unit > p_unit[i]) {
                min_lit_unit = p_unit[i];
                min_lit_index = i;
            }
        }

        ll cnt = n / lit[min_lit_index];
        total += cnt * p[min_lit_index];
        n -= cnt * lit[min_lit_index];
    }

    cout << total << endl;
    return 0;
}
