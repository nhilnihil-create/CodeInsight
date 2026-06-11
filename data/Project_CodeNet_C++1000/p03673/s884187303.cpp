#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = round(1e9+7);

int main() {
    int n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    vi ans;
    int index = n-1;
    rep(i,n) {
        ans.emplace_back(a[index]);
        if(i < (n-1)/2) index -= 2;
        else if(i > (n-1)/2)index += 2;
        else{
            if(index == 0) index = 1;
            else index = 0;
        }
    }

    rep(i,n) cout << ans[i] << " ";
    return 0;
}
