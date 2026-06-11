#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, l, t;
    cin >> n >> l >> t;
    vector<long long> x(n), w(n), last(n), ans(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> w[i];
    for(int i = 0; i < n; i++) {
        if(w[i] == 1) last[i] = (x[i] + t) % l;
        else last[i] = ((x[i] - t) % l + l) % l;
    }
    sort(last.begin(), last.end());
    long long cnt = 0;
    for(int i = 0; i < n; i++) {
        if(w[i] == 1) cnt -= (t - (l - x[i]) + l) / l;
        else cnt += (t - (x[i] + 1) + l) / l;
    }
    cnt = (cnt % n + n) % n;
    for(int i = 0; i < n; i++) ans[(i + cnt) % n] = last[i];
    for(int i = 0; i < n; i++) cout << ans[i] << endl;
    return 0;
}
