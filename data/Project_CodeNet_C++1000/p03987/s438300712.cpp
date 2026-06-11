#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    int a[n], pos[n + 1];
    REP(i,n){
        cin >> a[i];
        pos[a[i]] = i;
    }
    set<int> s;
    s.insert(-1);
    s.insert(n);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        auto itr = s.upper_bound(pos[i]);
        int right = *itr;
        itr--;
        int left = *itr;
        ans += (ll)i * (ll)(pos[i] - left) * (ll)(right - pos[i]);
        s.insert(pos[i]);
    }
    cout << ans << endl;
    return 0;
}