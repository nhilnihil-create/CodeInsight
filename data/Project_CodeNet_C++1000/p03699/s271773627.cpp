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
    vector<int> s(n);
    rep(i, n) cin >> s[i];
 
    int ans = 0;
    rep(i, n) ans += s[i];
    sort(s.begin(), s.end());
    if (ans%10==0) {
        rep(i, n) {
            int now = ans - s[i];
            if (now%10!=0) {
                cout << now << endl;
                return 0;
            }
        }
    }
    else {
        cout << ans << endl;
        return 0;
    }
    
    cout << 0 << endl;
    return 0;
}