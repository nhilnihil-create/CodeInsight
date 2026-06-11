#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

const int MAX_N = 110000;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    ll res = 0;

    for (int bit = 0; bit < (1 << (n - 1)); bit++) {
        ll tmp = 0;
        for (int i = 0; i < n - 1; i++) {
            tmp *= 10;
            tmp += s[i] - '0';
            if (bit & (1 << i))
                res += tmp, tmp = 0;
        }
        tmp *= 10;
        tmp += s.back() - '0';
        res += tmp;
    }
    cout << res << endl;

    return 0;
}