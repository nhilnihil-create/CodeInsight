#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {

    string S, T;
    int q;
    cin >> S >> T >> q;
    vector<int> s(S.length() + 1, 0), t(T.length() + 1, 0);
    rep(i,S.length()) s[i + 1] = S[i] == 'A' ? 1 : 2;
    rep(i,T.length()) t[i + 1] = T[i] == 'A' ? 1 : 2;

    vector<int> sum_S(S.length() + 1, 0), sum_T(T.length() + 1, 0);
    for (int i = 1; i <= S.length(); i++) sum_S[i] = sum_S[i - 1] + s[i];
    for (int i = 1; i <= T.length(); i++) sum_T[i] = sum_T[i - 1] + t[i];

    rep(i,q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ms = sum_S[b] - sum_S[a - 1];
        int mt = sum_T[d] - sum_T[c - 1];
        if (ms % 3 == mt % 3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}