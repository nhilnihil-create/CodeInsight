#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<bool> > vvb;
typedef map<int, bool> mib;

typedef long long ll;
typedef vector<long long> vl;
typedef pair<long long,long long> pll;
typedef vector<pair<long long,long long> > vpll;

typedef vector<string> vs;

typedef long double ld;

#define _GLIBCXX_DEBUG

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n-1); i >= 0; --i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define debug2(x, y) cerr << #x << ": " << x << ", " << #y << ": " << y << '\n'
#define debug3(x, y, z) cerr << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << '\n'
#define hyphen() cerr << "--\n"

#define ALL(vec) (vec).begin(), (vec).end()
#define REVALL(vec) (vec).rbegin(), (vec).rend()

static const int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};

#define fst first
#define snd second
#define pb push_back
#define mp(x,y) make_pair((x),(y))

const int MOD = (int)1e9 + 7;
const int INF = numeric_limits<int>::max();

// Sieve of Eratosthenes
vi get_primes(int input) {
    int N = max(input, 100);

    vb Alive(N, true);
    Alive.at(0) = false;
    Alive.at(1) = false;

    // i番目の素数が分かる (0-origin)
    vi Ps;

    FORE(smallest, 2, (int)(sqrt(N)+1)) {
        if (!Alive.at(smallest)) {
            continue;
        }

        for(int i = smallest * 2; i < N; i += smallest) {
            Alive.at(i) = false;
        }
    }

    REP(i, N) {
        if (Alive.at(i)) {
            Ps.pb(i);
        }
    }

    return Ps;
}


signed main() {
    int N, K;

    cin >> N >> K;

    string yes = "POSSIBLE";
    string no = "IMPOSSIBLE";

    int max_a = 0;
    vector<int> As(N);
    REP(i, N) {
        int A;
        cin >> A;
        As.at(i) = A;

        if (A == K) {
            cout << yes << endl;
            return 0;
        }

        if (A > max_a) {
            max_a = A;
        }
    }

    if (K > max_a) {
        cout << no << endl;
        return 0;
    }

    if (N == 1) {
        if (As.at(0) == K) {
            cout << yes << endl;
            return 0;
        } else {
            cout << no << endl;
            return 0;
        }
    }

    vi primes = get_primes(N);
    // 全てが共通の素因数を持っていたらNG
    // p < 10^5 まで調べればOK

    for (auto p : primes) {
        if (p > 100000) {
            break;
        }

        bool has_common = true;
        REP(i, N) {
            int A = As.at(i);
            // debug2(p, A);

            if (!(A % p == 0)) {
                // 次のprimeへ
                has_common = false;
                break;
            }
        }

        if (has_common) {
            if (K % p == 0) {
                cout << yes << endl;
            } else {
                cout << no << endl;
            }
            return 0;
        } else {
            continue;
        }
    }

    cout << yes << endl;
}

