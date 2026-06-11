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
/*!* [binsearch] *!*/
/*+* 二分探索 *+*/
// judge を満たすような下限を求める
// l:[X] 定義域外部の上限
// r:[X] 定義域外部の下限
// judge:[X -> bool] X を評価する関数
// lower:[bool] falseにすると代わりに上限を求める
// eps:[X] 終了距離

template <typename X>
X BinSearch(X l, X r, function<bool(X)> judge, bool lower = true, X eps = 1) {
    while (r - l > eps) {
        X m = (r + l) / 2;
        if (judge(m) == lower) {
            r = m;
        } else {
            l = m;
        }
    }
    return lower ? r : l;
}

int main() {
    // O(N(log N)^2)
    int N, L, Q;
    cin >> N;
    vector<int> X(N);
    for(int &x : X) cin >> x;
    cin >> L >> Q;
    int D = int(ceil(log2(N)));
    vector2d<int> seg(D, vector<int>(N));
    for (int d = 0; d < D; d++) {
        for (int i = 0; i < N; i++) {
            if(d == 0) {
                seg[d][i] = BinSearch<int>(i - 1, N, [&](int k) -> bool {
                    // 一日でk番までいけるか
                    return X[k] - X[i] <= L;
                }, false);
            } else {
                seg[d][i] = seg[d - 1][seg[d - 1][i]];
            }
        }
    }
    // O(N(log N)^2)
    for(int q = 0; q < Q; q++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(a > b) swap(a, b);
        // O((log N)^2)
        cout << BinSearch<int>(0, N, [&](int k) -> bool {
            // O(log N)
            // k日で到達できるか
            int x = a;
            for(int d = 0; d < D; d++) {
                if(k & (1 << d)) {
                    x = seg[d][x];
                }
            }
            return x >= b;
        }) << endl;
    }
    return 0;
}

