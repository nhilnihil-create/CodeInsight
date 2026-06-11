#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
    int n, m;
    cin >> n >> m;
    V<V<int>> g(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    deque<int> ans;
    ans.push_back(0);
    int v_b = 0;
    int v_f = 0;
    V<bool> seen(n);
    seen[0] = true;
    while(1) {
        bool ok = true;
        { // うしろ
            for(int nv : g[v_b]) {
                if(seen[nv] == false) {
                    ok = false;
                    seen[nv] = true;
                    v_b = nv;
                    ans.push_back(nv);
                    break;
                } 
            }
        }
        { // まえ
            for(int nv : g[v_f]) {
                if(seen[nv] == false) {
                    ok = false;
                    seen[nv] = true;
                    v_f = nv;
                    ans.push_front(nv);
                    break;
                } 
            }
        }
        if(ok) break;
    }

    cout << sz(ans) << endl;
    rep(i,sz(ans)) cout << ans[i]+1 << " ";
}