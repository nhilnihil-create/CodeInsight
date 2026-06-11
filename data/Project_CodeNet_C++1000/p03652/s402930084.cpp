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
using P = pair<int, int>;
int main() {
    const int INF = 1e8;
    int N, M;
    cin >> N >> M;
    // i -> (j, A)
    vector<set<P>> s(N);
    // (i, A) -> j
    vector2d<int> v(N, vector<int>(M));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int a;
            cin >> a;
            a--;
            s[i].insert({j, a});
            v[i][a] = j;
        }
    }
    int ans = INF;
    // (j, i, A)
    for(int m = 0; m < M; m++) {
        // 
        vector<int> cnt(M, 0);
        for(int n = 0; n < N; n++) {
            cnt[s[n].begin()->second]++;
        }
        int a = 0;
        for(int b = 0; b < M; b++) {
            if(cnt[a] < cnt[b]) a = b;
        }
        ans = min(ans, cnt[a]);
        for(int i = 0; i < N; i++) {
            s[i].erase({v[i][a], a});
        }
    }
    cout << ans << endl;
    return 0;
}

