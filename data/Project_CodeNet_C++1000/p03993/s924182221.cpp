#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll N; cin >> N;
    vector<ll> a(N, 0);
    rep(i,N) {
        cin >> a[i];
    }
    ll ans = 0;
    rep(i,N) {

        if (i+1 == a[a[i]-1]) {
            ans++;
        }

    }
    cout << ans / 2 << endl;


}
