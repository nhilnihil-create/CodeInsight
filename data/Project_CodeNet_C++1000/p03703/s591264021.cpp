#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<size_t I,class H,class...T>struct TupleReaderWriter{static tuple<H,T...> r(istream&i){H v;i>>v;return tuple_cat(tuple<H>(v),TupleReaderWriter<sizeof...(T)-1,T...>::r(i));}static void w(ostream&o,tuple<H,T...>&t,string d){TupleReaderWriter<I-1,H,T...>::w(o,t,d);o<<d<<get<I>(t);}};
template<class H,class...T>struct TupleReaderWriter<0,H,T...>{static tuple<H,T...> r(istream&i){H v;i>>v;return tuple<H>(v);}static void w(ostream&o,tuple<H,T...>&t,string d){o<<get<0>(t);}};
template<class...T>istream&operator>>(istream&i,tuple<T...>&t){t=TupleReaderWriter<sizeof...(T),T...>::r(i);return i;}
template<class...T>ostream&operator<<(ostream&o,tuple<T...>&t){string delim=" ";TupleReaderWriter<sizeof...(T)-1,T...>::w(o,t,delim);return o;}
template<class T>istream&operator>>(istream&i,vector<T>&v){for(auto&x:v)i>>x;return i;}
template<class T>ostream&operator<<(ostream&o,vector<T>&v){string delim="";for(auto&x:v)o<<delim<<x,delim=" ";return o;}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int x;fixprec(int d):x(d){}};
ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.x);}
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }

/*!* [segtree] *!*/
/*+* セグメント木 *+*/
// Tは f : T \to T$ についてモノイドである必要がある。
template <typename T = i64>
struct SegTree {
    using F = function<T(T, T)>;
    int N;
    vector<T> array;
    const F f;
    const T id;
    SegTree() {}
    // len : データ長, f : 二項演算, identity: 初期値(単位元)
    SegTree(int len, const F f, const T &id) : f(f), id(id) {
        for(N = 1; N < len; N <<= 1);
        array.assign(2 * N - 1, id);
    }
    // 値の更新 O(\log N)$
    // k : 添字, val : 値
    void update(int k, T val) {
        k += N;
        array[k] = val;
        while(k >>= 1) array[k] = f(array[2 * k], array[2 * k + 1]);
    }
    // 値の取り出し O(1)$
    // k : 添字
    T operator[] (int k) { return array[k + N]; }
    // 範囲検索 O(\log N)$
    // [L : R) の範囲について、f( [L : R) ) を求める
    T query(int l, int r) {
        T L = id, R = id;
        for(l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if(l & 1) L = f(L, array[l++]);
            if(r & 1) R = f(array[--r], R);
        }
        return f(L, R);
    }
};



int main() {
    i64 N, K;
    cin >> N >> K;
    vector<i64> a(N), s;
    // 累積和の値 -> 何番目に小さいか
    map<i64, int> s_inv;
    for(i64 &x : a) {
        cin >> x;
        x -= K;
    }
    {
        set<i64> tmp;
        i64 S = 0;
        tmp.insert(S);
        for(int i = 0; i < N; i++) {
            S += a[i];
            tmp.insert(S);
        }
        while(tmp.size()) {
            s_inv[*tmp.begin()] = s.size();
            s.push_back(*tmp.begin());
            tmp.erase(tmp.begin());
        }
    }
    // x -> y : x番目に小さい値の累積和がy個
    SegTree<int> seg(s.size() + 1, [](int x, int y) -> int {return x + y;}, 0);
    i64 ans = 0, S = 0;
    seg.update(s_inv[0], 1);
    for(int i = 0; i < N; i++) {
        S += a[i];
        ans += seg.query(0, s_inv[S] + 1);
        seg.update(s_inv[S], seg[s_inv[S]] + 1);
    }
    cout << ans << endl;
    return 0;
}

