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

vector<ll> p, q, sorted;
ll s[100010];
map<ll, ll> pos;

int main(){
    int n;
    cin >> n;
    rep(i, n) {
        ll a; cin >> a;
        if (i%2==0) p.push_back(a);
        else q.push_back(a);
        sorted.push_back(a);
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    sort(sorted.begin(), sorted.end());

    int j = 0, k = 0;
    rep(i, n) {
        if (i%2==0) s[i] = p[j], j++;
        else s[i] = q[k], k++;
    }

    ll cnt = 0;

    rep(i, n){
        pos[sorted[i]] = i;
    }

    rep(i, n){
        cnt += (pos[s[i]]%2 ^ i%2);
    }
    
    cout << cnt / 2 << endl;

    return 0;
}
