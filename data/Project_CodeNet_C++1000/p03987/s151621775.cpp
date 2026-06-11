#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e18;

int main(){
    int N;
    cin >> N;
    ll a[N+1], b[N+1];
    rep2(i, 1, N+1){
        cin >> a[i];
        b[a[i]] = i;
    }
    set<ll> s;
    s.insert(0), s.insert(N+1);
    ll ans = 0;
    rep2(i, 1, N+1){
        s.insert(b[i]);
        set<ll>::iterator ite, ite1, ite2;;
        ite = s.find(b[i]);
        ite1 = ite, ite2 = ite;
        ite1--, ite2++;
        ans += i*(*ite-*ite1)*(*ite2-*ite);
    }
    cout << ans << endl;
}