#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

class BIT
{
public:
    vector<int> bit;
    int M;

    BIT(int M):
        bit(vector<int>(M+1, 0)), M(M) {}

    int sum(int i) {
        if (!i) return 0;
        return bit[i] + sum(i-(i&-i));
    }

    void add(int i, int x) {
        if (i > M) return;
        bit[i] += x;
        add(i+(i&-i), x);
    }
};

signed main(){

    int N, M; cin >> N >> M;
    vec l(N), r(N);
    REP(i, N) cin >> l[i] >> r[i];

    vector<Pii> p(N);
    REP(i, N) p[i] = Pii(r[i] - l[i] + 1, i);
    SORT(p);

    int d0 = 1;
    vec ans(M + 1);
    BIT bit(M + 1), bit2(M + 1);
    REP(i, N){
        int D = p[i].first;
        int n = p[i].second;

        bit.add(1, 1);
        bit.add(D + 1, -1);

        FOR(d, d0 + 1, D + 1){
            FOR(k, 1, M / d + 1) ans[d] += bit2.sum(d * k);
        }
        d0 = D;
        bit2.add(l[n], 1);
        bit2.add(r[n] + 1, -1);
    }
    FOR(d, d0 + 1, M + 1){
        FOR(k, 1, M / d + 1) ans[d] += bit2.sum(d * k);
    }

    FOR(d, 1, M + 1) ans[d] += bit.sum(d);
    FOR(d, 1, M + 1) cout << ans[d] << endl;
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}