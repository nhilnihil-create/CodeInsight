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
void readvec(vector<T> &a);
void readindex(vector<int> &a);

int calc_ans(int i, vec &dp, map<int, set<int>> &m){
    if(dp[i] < INF) return dp[i];
    int p = m[i].size(), k = 0;
    vec tmp(p);
    for(int v: m[i]){
        tmp[k] = calc_ans(v, dp, m);
        k++;
    }
    SORT(tmp);
    int M = 0;
    REP(k, tmp.size()){
        M = max(M, tmp[k] + p);
        p--;
    }
    dp[i] = M;
    return dp[i];
}

signed main(){

    int N; cin >> N;
    vec a(N - 1); readvec(a);
    map<int, set<int>> m;
    REP(i, N - 1) m[a[i] - 1].insert(i + 1);

    vec dp(N, INF);
    cout << calc_ans(0, dp, m);
    //REP(i, N) cout << i + 1 << ", " << dp[i] << endl;

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