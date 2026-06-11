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
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m);
    rep(i, m) {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }
    vector<int> tot(n + 1, 1);
    vector<bool> check(n + 1, false);
    check[0] = true;
    rep(i, m) {
        tot[x[i]]--;
        tot[y[i]]++;
        if(check[x[i]]) {
            check[y[i]] = true;
            if(tot[x[i]] == 0) check[x[i]] = false;
        }
    }
    int ans = 0;
    for(auto x : check) if(x) ans++;

    cout << ans << endl;
    
    return 0;
}