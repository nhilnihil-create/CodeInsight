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
    vector<bool> v(8);
    int num = 0;
    rep(i, n) {
        if (a[i]<3200) {
            v[a[i]/400] = true;
        }
        else {
            num++;
        }
    }
    int ans1 = 0;
    rep(i, 8) {
        if (v[i]) ans1++;
    }
    int ans2 = ans1 + num;
    ans1 = max(ans1, 1);
    
    
    cout << ans1 << " " << ans2 << endl;

    return 0;
}
