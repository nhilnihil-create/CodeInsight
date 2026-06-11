#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll N; cin >> N;
        vector<ll> a(N, 0);
        map<ll, ll> m;
        for (int i = 0; i < N; ++i) {
                cin >> a[i];
                m[a[i]]++;
        }
        vector<ll> T;
        for (auto i : m) {
                T.push_back(i.first);
        }

        ll ans = 0;
        for (int i = 0; i < T.size(); ++i) {
                ll tmp = T[i];
                ll sum = m[tmp] + m[tmp+1] + m[tmp+2];
                if (ans < sum) ans = sum;
        }
        cout << ans << endl;

}
