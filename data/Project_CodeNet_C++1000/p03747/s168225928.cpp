#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<class F>auto recursive(F f){return[f](auto...a){return f(f,a...);};}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int p;fixprec(int p):p(p){}};
ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.p);}

i64 pmod(i64 x, i64 m) {
    return (x % m + m) % m;
}

using P = pair<i64, i64>;
int main() {
    i64 N, L, T;
    cin >> N >> L >> T;
    vector<P> data(N);
    for(P&d : data) {
        cin >> d.first >> d.second;
        if(d.second == 2) d.second = -1;
    }
    i64 a0, w0, x0;
    vector<i64> ans(N);
    for(int i = 0; i < N; i++) {
        i64 x, w;
        tie(x, w) = data[i];
        ans[i] = pmod(x + w * T, L);
    }
    tie(x0, w0) = data[0];
    a0 = ans[0];
    sort(WHOLE(ans));
    int k;
    for(int i = 0; i < N; i++) {
        if(ans[i] == a0) {
            k = i;
            if(w0 == -1) break;
        }
    }
    i64 shift = 0;
    for(int i = 1; i < N; i++) {
        if(w0 != data[i].second) {
            i64 D;
            if(w0 == 1) {
                D = data[i].first - x0;
            } else {
                D = x0 + L - data[i].first;
            }
            if(D <= 2 * (T % L)) shift++;
            if(D + L <= 2 * (T % L)) shift++;
            shift += 2 * (T / L);
            shift %= N;
        }
    }
    for(int i = 0; i < N; i++) {
        cout << ans[pmod(k - w0 * shift + i, N)] << endl;
    }
    return 0;
}