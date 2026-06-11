#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll N;
        cin >> N;
        map<ll, ll> m;
        for (int i = 0; i < N; ++i) {
                ll A; cin >> A;
                m[A]++;
        }

        ll ans = 0;
        for (auto i : m) {

                if (i.second % 2) ans++;

        }
        cout << ans << endl;


}
