#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define nyan "(=^･ω･^=)"
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 3e5+10;
int a[maxn];

void add(int idx, int v) {
    while(idx <= maxn) {
        a[idx] += v;
        idx += idx & (-idx);
    }
}
int query(int idx) {
    int ret = 0;
    while(idx) {
        ret += a[idx];
        idx -= idx & (-idx);
    } return ret;
}

bool cmp(pii a, pii b) {
    return a.second - a.first < b.second - b.first; 
}

int main()
{
    int n, m;
    vector<pii> v;

    cin >> n >> m;
    for(int i = 0, l, r; i < n; i++) {
        cin >> l >> r;
        v.pb({l, r});
    }
    sort(v.begin(), v.end(), cmp);
    
    for(int d = 1, j = 0; d <= m; d++) {
        for(; v[j].second - v[j].first + 1 < d && j < n; j++) 
            add(v[j].first, 1), add(v[j].second+1, -1);

        int ans = n-j;
        for(int i = 0; i <= maxn; i += d)
            ans += query(i);

        cout << ans << endl;
    }
    return 0;
}