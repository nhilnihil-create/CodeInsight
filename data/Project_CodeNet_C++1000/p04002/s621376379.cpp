#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }

int is_exist(int i, int j, vector<Pii> &ab){
    int n = Lower_bound(ab, Pii(i, j));
    if(n != ab.size() && ab[n] == Pii(i, j)) return 1;
    else return 0;
}

int count(int i, int j, int H, int W, vector<Pii> &ab){
    if(i < 0 || j < 0 || i >= H - 2 || j >= W - 2) return -1;
    int n = 0;
    REP(x, 3) REP(y, 3) n += is_exist(i + x, j + y, ab);
    return n;
}

signed main(){

    int H, W, N; cin >> H >> W >> N;
    int a, b; vector<Pii> ab(N);
    REP(i, N){
        cin >> a >> b;
        ab[i] = Pii(a - 1, b - 1);
    }
    SORT(ab);

    vec ans(10, 0);
    set<Pii> s;
    REP(i, N){
        int i0 = ab[i].first, j0 = ab[i].second;
        FOR(x, -2, 1) FOR(y, -2, 1){
            if(s.count(Pii(i0 + x, j0 + y)) > 0) continue;
            int n = count(i0 + x, j0 + y, H, W, ab);
            if(n > 0){
                ans[n]++;
                s.insert(Pii(i0 + x, j0 + y));
            }
        }
    }
    ans[0] = (H - 2) * (W - 2);
    FOR(i, 1, 10) ans[0] -= ans[i];
    REP(i, 10) cout << ans[i] << endl;

    return 0;
}
