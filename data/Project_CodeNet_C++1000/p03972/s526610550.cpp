#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int W, H;
    ll p[100005], q[100005];
    ll sum = 0ll;
    cin >> W >> H;

    for (int i = 0; i < W; i++) cin >> p[i];
    for (int i = 0; i < H; i++) cin >> q[i];
    
    sort(p, p + W); sort(q, q + H); 
    int i = 0, j = 0;
    while (i < W || j < H) {
        if (i < W && (j >= H || p[i] < q[j])) sum += p[i] * (H - j + 1), i++;
        else sum += q[j] * (W - i + 1), j++;
    }

    cout << sum << endl;
    return (0);
}