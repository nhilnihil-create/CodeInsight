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
int main() {
    // 全てのAをBにすると考えて、3を法として同値類で扱う
    string S, T;
    cin >> S >> T;
    vector<int> X(S.size()), Y(T.size());
    for(int i = 0; i < S.size(); i++) {
        X[i] = ( (i ? X[i - 1] : 0) + (S[i] == 'A' ? 2 : 1));
    }
    for(int i = 0; i < T.size(); i++) {
        Y[i] = ( (i ? Y[i - 1] : 0) + (T[i] == 'A' ? 2 : 1));
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        int x_val = X[b] - (a ? X[a - 1] : 0);
        int y_val = Y[d] - (c ? Y[c - 1] : 0);
        R_YESNO((x_val - y_val) % 3 == 0);
    }
    return 0;
}

