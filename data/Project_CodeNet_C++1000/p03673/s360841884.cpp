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
    deque<int> q;
    bool flip = false;
    rep(i, n) {
        if (!flip) {
            q.push_back(a[i]);
        }
        else {
            q.push_front(a[i]);
        }
        flip = !flip;
    }

    rep(i, n) {
        int ans;
        if (!flip) {
            ans = q.front();
            q.pop_front();
        }
        else {
            ans = q.back();
            q.pop_back();
        }
        cout << ans << " ";
    }
    cout << endl;
    
    return 0;
}
