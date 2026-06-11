#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S, T;
    cin >> S >> T;

    vi prefS(S.size() + 1);
    prefS[0] = 0;
    for (int i = 0; i < S.size(); i++) {
        prefS[i+1] = prefS[i] + (S[i] == 'A' ? 1 : 2);
    }

    vi prefT(T.size() + 1);
    prefT[0] = 0;
    for (int i = 0; i < T.size(); i++) {
        prefT[i+1] = prefT[i] + (T[i] == 'A' ? 1 : 2);
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;

        int sumS = (prefS[b+1] - prefS[a]) % 3;
        int sumT = (prefT[d+1] - prefT[c]) % 3;
        cout << (sumS == sumT ? "YES\n" : "NO\n");
    }

    return 0;
}

