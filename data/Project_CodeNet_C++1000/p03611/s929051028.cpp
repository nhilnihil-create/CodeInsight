#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll N; cin >> N;
    vector<ll> a(N, 0);
    map<ll,ll> m;
    rep(i,N) {
        cin >> a[i];
        m[a[i]]++;
    }
    vector<ll> T;
    for (auto i : m) {
        T.push_back(i.first);
    }
    ll maxv = 0;
    rep(i,T.size()) {
        ll index = T[i];
        if (maxv < m[index] + m[index-1] + m[index+1]) {
            maxv = m[index] + m[index-1] + m[index+1];
        }
    }
    cout << maxv << endl;

}
