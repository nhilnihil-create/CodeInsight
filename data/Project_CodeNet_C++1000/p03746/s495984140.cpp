#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
const int INF = 1e18;


signed main(){
    int n, m; cin >> n >> m;
    vector<int> G[n];
    vector<bool> used(n,false);
    deque<int> ans;
    int left_t,right_t;
    REP(i,m){
        int a, b; cin >> a >> b; a--; b--;
        if(i == 0){
            ans.push_front(a);
            ans.push_back(b);
            left_t = a;
            right_t = b;
            used[a] = used[b] = true;
        }
        G[a].eb(b);
        G[b].eb(a);
    }
    labl1:;
    for(auto v:G[left_t]){
        if(!used[v]){
            ans.push_front(v);
            used[v] = true;
            left_t = v;
            goto labl1;
        }
    }
    labl2:;
    for(auto v:G[right_t]){
        if(!used[v]){
            ans.push_back(v);
            used[v] = true;
            right_t = v;
            goto labl2;
        }
    }
    int k = SZ(ans);
    cout << k << '\n';
    REP(i,k){
        cout << ans.front()+1 << " ";
        ans.pop_front();
    }
}