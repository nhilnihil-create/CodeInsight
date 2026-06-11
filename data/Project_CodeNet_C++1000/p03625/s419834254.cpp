#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(whole(a));
    map<int, int> mp;
    rep(i, n) mp[a[i]]++;
    ll ans = 0;
    auto it = mp.end();
    vector<ll> x;
    while (1) {
        it--;
        //debug(it->second);
        if (it->second<=1) {
            if (it==mp.begin()) break;
            continue;
        }
        x.push_back(it->first);
        it->second -= 2;
        it++;
        if (x.size()==2) break;
        if (it==mp.begin()) break;
    }
    //debug(x.size());
    if (x.size()==2) ans = x[0]*x[1];
    
    cout << ans << endl;
    return 0;
}
