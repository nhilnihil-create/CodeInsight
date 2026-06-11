#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define rep11(i,n) for(int i=1;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define repm(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sperase(v,n) (v).erase(remove(all(v), n), (v).end())
#define vdelete(v) (v).erase(unique(all(v)), (v).end())
#define pb(n) push_back(n)
#define mp make_pair
#define MOD 1000000007
#define INF LONG_LONG_MAX

int n,m,a,b;
vector<int> v[100001];
deque<int> ans;
bool visited[100001];

void kr(int k, bool f) {
    visited[k] = true;
    for(auto i : v[k]) {
        if (!visited[i]) {
            if (f) ans.push_front(i);
            else ans.push_back(i);
            kr(i,f);
            return;
        }
    }
}


signed main() {
    cin >> n >> m;
    rep(i,m) {
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    ans.pb(1);
    kr(1,false);
    kr(1,true);
    cout << ans.size() << endl;
    for(auto i : ans) cout << i << " ";cout << endl;
}


