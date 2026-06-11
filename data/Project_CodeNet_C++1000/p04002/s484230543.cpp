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

signed main(){

    int H, W, N; cin >> H >> W >> N;
    int a, b;
    map<Pii, int> m;
    REP(n, N){
        cin >> a >> b;
        FOR(x, -2, 1) FOR(y, -2, 1){
            int i = a - 1 + x, j = b - 1 + y;
            if(i >= 0 && j >= 0 && i < H - 2 && j < W - 2) m[Pii(i, j)] += 1;
        }
    }

    vec ans(10, 0);
    for(auto p: m) ans[p.second]++;
    
    ans[0] = (H - 2) * (W - 2);
    FOR(i, 1, 10) ans[0] -= ans[i];
    REP(i, 10) cout << ans[i] << endl;

    return 0;
}