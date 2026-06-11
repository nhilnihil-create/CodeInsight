#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define fore(i, x) for (auto &i : n)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(i, n) for (int i = n; i >= 0; --i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int mod = 1000000000 + 7;
const static int inf = INT_MAX / 2;
const static llong INF = LLONG_MAX / 2;
const static double eps = 1e-10;
const static int dx[] = {1, 0, -1, 0};
const static int dy[] = {0, 1, 0, -1};

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0;}

template<typename T > struct SparseTable { //[a, b)
    vector<vector<T> > st;
    vector< int > lookup;
    int type;
    SparseTable(const vector<T> &v, const int t) { // type == 1 range minimum type == 2 range maximum
        int b = 0;
        type = t;
        while((1 << b) <= v.size()) ++b;
        st.assign(b, vector< T >(1 << b));
        for(int i = 0; i < v.size(); i++) {
            st[0][i] = v[i];
        }

        for(int i = 1; i < b; i++) {
            for(int j = 0; j + (1 << i) <= (1 << b); j++) {
                st[i][j] = type ? min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]) : max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
        
        lookup.resize(v.size() + 1);
        
        for(int i = 2; i < lookup.size(); i++) {
            lookup[i] = lookup[i >> 1] + 1;
        }
    }
        
    inline T rmq(int l, int r) {
        int b = lookup[r - l];
        return type ? min(st[b][l], st[b][r - (1 << b)]) : max(st[b][l], st[b][r - (1 << b)]);
    }
};

signed main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    map<int, int> M;
    SparseTable<int> st(A, 0);
    for (int i = 0; i < n - 1; ++i) {
        ++M[st.rmq(i + 1, n + 1) - A[i]];
    }

    auto itr = M.end();
    --itr;
    cout << itr-> second << endl;

    return 0;
}