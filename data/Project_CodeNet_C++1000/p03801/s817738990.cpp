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
    int N;
    cin >> N;
    vector<i64> A(N), ans(N, 0);
    for(i64 &x : A) cin >> x;
    deque<int> deq;
    for(int i = N - 1; i >= 0; i--) {
        while(!deq.empty() && A[i] > A[deq.front()]) {
            deq.pop_front();
        }
        deq.push_front(i);
    }
    priority_queue<i64> q;
    int cur, prev = N;
    // prevと同じ高さの山の数
    i64 m = 0;
    while(!deq.empty()) {
        // 取る必要のある石の数
        i64 S = 0;

        cur = deq.back(); deq.pop_back();
        // 右側の山を、取る山キューに追加
        if(prev >= 0) {
            for(int i = cur; i < prev; i++) {
                q.push(A[i]);
            }
        }
        if(prev < N) {
            ans[prev] += (A[prev] - A[cur]) * m;
        }
        while(q.size() && q.top() >= A[cur]) {
            S += q.top() - A[cur];
            q.pop();
            m++;
        }
        if(prev < N) ans[prev] += S;
        prev = cur;
    }
    ans[prev] = accumulate(WHOLE(A), - accumulate(WHOLE(ans), i64(0)));
    for(i64 x : ans) cout << x << endl;
    return 0;
}

