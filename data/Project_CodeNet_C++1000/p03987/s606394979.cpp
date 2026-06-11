#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> a(N), b(N);
    Rep (i, N) {
        cin >> a[i];
        a[i]--;
        b[a[i]] = i;
    }

    set<ll> pos;
    pos.insert(-1);
    pos.insert(N);

    ll ans = 0;
    Rep (i, N) {
        pos.insert(b[i]);
        auto itr = pos.find(b[i]);
        itr++;
        ll l = *itr;
        itr--;
        itr--;
        ll r = *itr;
        ans += (i+1) * (l-b[i]) * (b[i]-r);
    }

    cout << ans << endl;
}