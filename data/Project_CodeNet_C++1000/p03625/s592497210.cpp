#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    int n; scanf("%d", &n);
    map <ll, int> mp;
    for (int i = 0; i < n; i++) {
        ll x; scanf("%lld", &x);
        mp[x]++;
    }

    vector <ll> vec;
    for (auto pp : mp) {
        int cnt = pp.second;
        cnt /= 2;
        while (cnt > 0) {
            vec.push_back(pp.first);
            cnt--;
        }
    }

    if (vec.size() < 2) {
        puts("0");
        return 0;
    }

    int sz = vec.size();
    printf("%lld\n", vec[sz - 1] * vec[sz - 2]);
}