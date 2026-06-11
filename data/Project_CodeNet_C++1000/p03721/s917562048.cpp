#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> num(100100, 0);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        num[a] += b;
    }
    int ans;
    ll tot = 0;
    rep(i, num.size()) {
        tot += num[i];
        if(tot >= k) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    
    return 0;
}