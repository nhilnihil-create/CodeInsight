#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N;
    cin >> N;
    vector<pair<ll, int>> a(N);
    for (int i = 0; i < N; i++) {
        ll n;
        scanf("%lld", &n);
        a[i] = {n, i};
    }
    sort(a.begin(), a.end());
    ll low = 0;
    int high_index = 0;
    vector<bool> check(N, false);
    vector<ll> ans(N, 0);
    ll cnt = 0;
    for (int t = 0; t < N; t++) {
        int pos = a[t].second;
        ll h = a[t].first;
        check[pos] = true;
        cnt += h - low;
        if (pos == high_index) {
            ans[pos] += cnt;
            ans[pos] += (N-1-t)*(h-low);
            low = h;
            cnt = 0;
            while (check[high_index]) high_index++;
        }
    }
    
    for (int i = 0; i < N; i++) printf("%lld\n", ans[i]);
    
    return 0;
}