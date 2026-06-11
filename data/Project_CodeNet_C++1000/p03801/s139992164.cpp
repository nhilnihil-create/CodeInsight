#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    map<int, int> mp;
    mp[0] = 0;
    rep(i, N) {
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<int> k(0);
    for (auto i = mp.begin(); i != mp.end(); i++) {
        k.push_back(i->first);
    }
    sort(k.begin(), k.end());
    //rep(i, k.size()) cout << k[i] << mp[k[i]] << endl;
    int j = 0;
    ll d = N;
    rep(i, N) {
        ll c = 0;
        while (a[i] > k[j]) {
            c += d * (k[j + 1] - k[j]);
            j++;
            d -= mp[k[j]];
        }
        cout << c << endl;
    }
}