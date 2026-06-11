#include "bits/stdc++.h"

using namespace std;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
#define ll long long

ll d[maxn * 2];

int main() {
    //freopen("input.txt", "r", stdin);
    ll n, m, temp,x, l, r, ans = 0;
    cin >> n >> m >> temp;
    for (int i = 1; i < n; i++) {
        cin >> x;
        r = x;
        l = temp;
        if (l > r)
            r += m;
        ans += r - l;
        if (r - l > 1) {
            d[l + 2] += 1;
            d[r + 1] -= (r - l);
            d[r + 2] += (r - l - 1);
        }
        temp = x;
    }
    for(int i=1;i<=2*m;i++) d[i]+=d[i-1];
    for(int i=1;i<=2*m;i++) d[i]+=d[i-1];
    ll maxx = 0;
    for(int i=1;i<=m;i++)
        maxx = max(maxx,d[i]+d[i+m]);
    cout<<ans-maxx<<endl;
    return 0;
}

