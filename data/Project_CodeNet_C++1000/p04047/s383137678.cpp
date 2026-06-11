#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

vector<int> v;

int main(){
    int n;
    cin >> n;
    rep(i, 2*n){
        int l;
        cin >> l;
        v.push_back(l);
    }
    sort(v.rbegin(), v.rend());
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += v[2*i+1];
    }
    cout << ans << endl;

    return 0;
}
