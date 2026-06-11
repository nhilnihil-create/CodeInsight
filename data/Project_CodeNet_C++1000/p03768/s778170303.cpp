#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template <size_t I, class H, class... T> struct TupleReaderWriter{static tuple<H,T...> r(istream&i){H v;i>>v;return tuple_cat(tuple<H>(v),TupleReaderWriter<sizeof...(T)-1,T...>::r(i));}static void w(ostream&o,tuple<H,T...>&t,string d){TupleReaderWriter<I-1,H,T...>::w(o,t,d);o<<d<<get<I>(t);}};
template <class H, class... T> struct TupleReaderWriter<0,H,T...>{static tuple<H,T...> r(istream&i){H v;i>>v;return tuple<H>(v);}static void w(ostream&o,tuple<H,T...>&t,string d){o<<get<0>(t);}};
template<class T>istream&operator>>(istream&i,vector<T>&v){for(auto&x:v)i>>x;return i;}
template<class T>ostream&operator<<(ostream&o,vector<T>&v){string delim="";for(auto&x:v)o<<delim<<x,delim=" ";return o;}
template <class... T> istream& operator>>(istream&i,tuple<T...>& t) { t = TupleReaderWriter<sizeof...(T), T...>::r(i); return i; }
template <class... T> ostream& operator<<(ostream& o, tuple<T...>& t) { string delim = " "; TupleReaderWriter<sizeof...(T) - 1, T...>::w(o, t, delim); return o; }
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vector2d = vector<vector<T>>;
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
// 再帰的に塗ると考える
int main() {
    const int MAX_D = 10;
    int N, M, Q;
    cin >> N >> M;
    vector2d<int> edge(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    cin >> Q;
    // 操作に対応する色
    vector<int> C(Q + 1, 0);
    // (u, d) -> q : 頂点uと操作q(頂点v)について、u,v間距離がd以下となる最新のq
    vector2d<int> dp(N, vector<int>(MAX_D + 1, 0));
    for(int q = 1; q <= Q; q++) {
        int v, d, c;
        cin >> v >> d >> c;
        v--;
        C[q] = c;
        dp[v][d] = q;
    }
    // O(MD)
    for(int d = MAX_D - 1; d >= 0; d--) {
        // O(M)
        for(int v = 0; v < N; v++) {
            dp[v][d] = max(dp[v][d], dp[v][d + 1]);
            for(int w : edge[v]) {
                dp[v][d] = max(dp[v][d], dp[w][d + 1]);
            }
        }
    }
    for(int v = 0; v < N; v++) {
        cout << C[dp[v][0]] << endl;
    }
    return 0;
}