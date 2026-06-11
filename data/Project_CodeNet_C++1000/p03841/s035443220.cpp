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

#define ANS(f) if(f) cout << "YES" << endl; else cout << "NO" << endl;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }



signed main(){

    int N; cin >> N;
    vec x0(N);
    vector<Pii> x(N);
    vec ans(N * N, INF);
    REP(i, N){
        cin >> x0[i];
        x0[i]--;
        x[i] = Pii(x0[i], i);
        ans[x0[i]] = i;
    }
    SORT(x);
    int i0 = 0;
    REP(i, N){
        int n = x[i].second;
        //ans[x[i].first] = n;
        REP(i, n){
            while(ans[i0] < INF) i0++;
            ans[i0] = n;
        }
    }
    REP(i, N){
        int n = x[i].second;
        REP(i, N - n - 1){
            while(ans[i0] < INF) i0++;
            ans[i0] = n;
        }
    }

    bool f = true;
    vec cnt(N, 0);
    REP(i, N * N){
        cnt[ans[i]]++;
        if(cnt[ans[i]] == ans[i] + 1) if(x0[ans[i]] != i) f = false;
    }

    if(f){
        cout << "Yes" << endl;
        REP(i, N * N) cout << ans[i] + 1 << " ";
    }else cout << "No" << endl;

    
    return 0;
}