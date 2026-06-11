#include <bits/stdc++.h>
#include <random>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
//#define ll __int128
//#define int ll
//#define char ll
//#define double ld
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<short> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<string> vst;
typedef vector<vst> vvst;
typedef pair<ld, ld> pld;

#define inmin(a, b) a = min(a, (b))
#define inmax(a, b) a = max(a, (b))
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define sqr(x) ((x) * (x))
#define fori(i, n) for(int i = 0; i < int(n); ++i)
#define SZ(a) ((int)((a).size()))
#define triple(T) tuple<T, T, T>
#define quad(T) tuple<T, T, T, T>
#define watch(x) cerr << (#x) << " = " << (x) << endl;

#ifdef MAX_HOME
#define cerr cout
#else
#define cerr if (false) cerr
#endif

const double PI = 2 * acos(0.0);
#define rand shittttty_shit
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());

const string DIGITS = "0123456789";
const string ALPH = "abcdefghijklmnopqrstuvwxyz";


template<class T0, class T1>
inline ostream &operator<<(ostream &out, pair<T0, T1> &a) {
    return out << "{" << a.first << ", " << a.second << "}";
}

template<class T0, class T1>
inline istream &operator>>(istream &in, pair<T0, T1> &a) {
    return in >> a.first >> a.second;
}

template<class T0, class T1, class T2>
inline ostream &operator<<(ostream &out, tuple<T0, T1, T2> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << "}";
}

template<class T0, class T1, class T2, class T3>
inline ostream &operator<<(ostream &out, tuple<T0, T1, T2, T3> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ", " << get<3>(a) << "}";
}

template<class T>
inline ostream &operator<<(ostream &out, vector<T> &a) {
    out << "[";
    fori (i, a.size())out << a[i] << vector<string>{", ", "]  "}[i + 1 == a.size()];
    return out;
}


void smain();


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef MAX_HOME
    freopen("input.txt", "r", stdin);
    clock_t start = clock();
#endif
#ifdef HK_CUP
    freopen("finput.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout << setprecision(12) << fixed;
    smain();
#ifdef MAX_HOME
#ifndef HK_CUP
    cout << "\n\nTOTAL EXECUTION TIME: " << float(clock() - start) / CLOCKS_PER_SEC << endl;
#endif
#endif
    return 0;
}

const int N = 1e5 + 10;
int n;
int a[N];
int L;
const int LOG = 20;
int pr[N][LOG];
int cost[N][LOG];

void build_graph() {
    for (int i = n - 1; i >= 0; --i) {
        int l = i, r = n;
        while (r - l > 1) {
            int m = r + l >> 1;
            if (a[m] - a[i] <= L) {
                l = m;
            } else {
                r = m;
            }
        }
        pr[i][0] = l;
        cost[i][0] = 1;
    }

    for (int h = 1; h < LOG; ++h) {
        for (int i = 0; i < n; ++i) {
            pr[i][h] = pr[pr[i][h - 1]][h - 1];
            cost[i][h] = cost[i][h - 1] + cost[pr[i][h - 1]][h - 1];
        }
    }
}


void smain() {

    cin >> n;
    fori (i, n) {
        cin >> a[i];
    }
    cin >> L;
    build_graph();
    int q;
    cin >> q;
    fori (_, q) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        --l, --r;
        if (l > r)
            swap(l, r);
        for (int h = LOG - 1; h >= 0; --h) {
            if (pr[l][h] < r) {
                ans += 1 << h;
                l = pr[l][h];
            }
        }
        cout << ans + 1 << '\n';
    }
}