#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50, INF = (int)1e9 + 50;
typedef pair<int, int> P;

int n;
P p[N];
ll res[N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i].first, p[i].second = i;
    sort(p, p + n, greater<>());
    int r = 0;
    int mn = INF;
    for(int i = 0; i < n; ) {
        while(r < n && p[r].first == p[i].first) {
            mn = min(mn, p[r].second);
            r++;
        }
        res[mn] += 1LL * (p[i].first - p[r].first) * r;
        i = r;
    }
    for(int i = 0; i < n; i++) cout << res[i] << "\n";
}