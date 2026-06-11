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
    const i64 INF = 1e16;
    int N, M;
    cin >> N >> M;
    i64 S = 0;
    vector<i64> A(N);
    rev_priority_queue<pair<i64, int>> q;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    set<int> shortcut, inv_range;
    i64 L = 0;
    for(int i = 0; i < N - 1; i++) {
        S += (A[i + 1] - A[i] + M) % M;
        if(A[i] < A[i + 1]) { // 向きが同じ
            q.push({A[i], i});
            q.push({A[i + 1], i});
        } else { //
            q.push({A[i + 1], i});
            q.push({A[i], i});
            inv_range.insert(i);
            shortcut.insert(i);
            L += A[i];
        }
    }
    i64 ans = INF;

    for(int x = 0; x < M; x++) {
        i64 cand = 0;
        cand = S;
        cand -= x * shortcut.size() - L + inv_range.size() * M;
        cand += shortcut.size();
        ans = min(ans, cand);
        while(q.size() && x >= q.top().first) {
            i64 a; int i;
            tie(a, i) = q.top();
            inv_range.erase(i);
            if(shortcut.count(i)) {
                shortcut.erase(i);
                L -= A[i];
            } else {
                shortcut.insert(i);
                L += A[i];
            }
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}

