#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(a) sort(a.begin(), a.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define Ans(f, y, n) if(f) cout << y << endl; else cout << n << endl;
#define int long long
#define INF 1000000000000000000
using namespace std;

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;
using bools = vector<bool>;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }
template<typename T>
void debug(vector<vector<T>> m){ REP(i, m.size()){ REP(j, m[i].size()){ cout << m[i][j] << ","; } cout << endl;} }



signed main(){

    int N; cin >> N;
    vec a(N); readv(a);
    int M = -1, m = N;
    vec cnt(N, 0);
    REP(i, N){
        Max(M, a[i]);
        Min(m, a[i]);
        cnt[a[i]]++;
    }
    bool ans = false;
    if(m == (M + 1) / 2){
        ans = true;
        if(M % 2 == 0){
            if(cnt[m] != 1) ans = false;
            FOR(i, m + 1, M + 1) if(cnt[i] < 2) ans = false;
        }else{
            if(cnt[m] != 2) ans = false;
            FOR(i, m + 1, M + 1) if(cnt[i] < 2) ans = false;
        }
    }
    Ans(ans, "Possible", "Impossible");
    
    return 0;
}