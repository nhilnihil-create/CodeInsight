#include <bits/stdc++.h>
#include <random>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
//#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef pair<ld, ld> pld;

#define inmin(a, b) a = min(a, (b))
#define inmax(a, b) a = max(a, (b))
#define mp(a, b) make_pair((a), (b))
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define SZ(a) ((int)((a).size()))
#define watch(x) cerr << (#x) << " = " << (x) << endl;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());

template<class T0, class T1>
inline ostream &operator<<(ostream &out, pair<T0, T1> &a) {
    return out << "{" << a.first << ", " << a.second << "}";
}

template<class T>
inline ostream &operator<<(ostream &out, vector<T> &a) {
    out << "[";
    for (int i = 0; i < a.size(); i++)
        out << a[i] << vector<string>{", ", "]  "}[i + 1 == a.size()];
    return out;
}


void smain();

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef RUS_HOME
    freopen("input.txt", "r", stdin);
    clock_t start = clock();
#else
    //    freopen("king.in", "r", stdin);
    //    freopen("king.out", "w", stdout);
#endif

    cout << setprecision(12) << fixed;
    smain();

#ifdef RUS_HOME
    cout << "\n\n\n\nTOTAL EXECUTION TIME: " << float(clock() - start) / CLOCKS_PER_SEC << endl;
#endif

    return 0;
}

void smain() {

    int n, l;
    cin >> n >> l;
    vi a(n);
    int pos = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) {
            if (a[i] + a[i - 1] >= l) {
                pos = i;
            }
        }
    }
    if (pos == -1) {
        cout << "Impossible";
        return;
    }


    cout << "Possible\n";

    for (int i = 0; i < pos - 1; i++) {
        cout << i + 1 << "\n";
    }

    for (int i = n - 2; i >= pos; i--) {
        cout << i + 1 << "\n";
    }

    cout << pos << "\n";

}