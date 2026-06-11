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

int n,x,now;
deque<pair<int,int>> v,vv,vvv;
vector<int> ans;
bool ok[501];

signed main() {
    cin >> n;
    rep1(i,n) {
        cin >> x;
        v.pb(mp(x,i));
    }
    ok[1]=true;
    sort(all(v));
    for(auto i : v) if (i.se > 1) vv.pb(mp(i.se, i.se-1));
    for(auto i : v) {
        int b=i.fi-ans.size()-1;
        while(b && vv.size()) {
            rep(j,min(b,vv.front().se)) ans.pb(vv.front().fi);
            if (vv.front().se <= b) {
                ok[vv.front().fi] = true;
                b -= vv.front().se;
                vv.pop_front();
            } else {
                vv.front().se -= b;
                b = 0;
            }
        }
        while(b && vvv.size()) {
            rep(j,min(b,vvv.front().se)) ans.pb(vvv.front().fi);
            if (vvv.front().se <= b) {
                b -= vvv.front().se;
                vvv.pop_front();
            } else {
                vvv.front().se -= b;
                b = 0;
            }
        }
        if (b || !ok[i.se]) {
            cout << "No" << endl;
            return 0;
        }
        ans.pb(i.se);
        vvv.pb(mp(i.se, n-i.se));
    }
    for(auto i : vvv) rep(j,i.se) ans.pb(i.fi);
    cout << "Yes" << endl;
    for(auto i : ans) cout << i << " ";cout << endl;
}



