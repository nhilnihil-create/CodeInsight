#include <bits/stdc++.h>

//#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int maxn = 1e5+5;
    int a[maxn];
    int bad[maxn];
    int good[maxn];
    int cnt[maxn];
    for (int i = 0; i < maxn; i++) {
        cnt[i] = bad[i] = good[i] = a[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (int i = 0; i < maxn; i++) {
        if (cnt[i]%2==1) bad[i%m]++;
        good[i%m] += (cnt[i]/2)*2;
        /*if (cnt[i] >= 1) {
            cout << " now bad " << i%m << " is " << bad[i%m] << '\n';
            cout << " good " << i%m << " is " << good[i%m] << '\n';
        }*/
    }

    int res = 0;

    for (int i = 0; i < m; i++) {
        int j = (m-i)%m;
        /*cout << " i = "<< i << " j = " << j << "\n";
        cout << " good i: " << good[i] << " bad i: " << bad[i] << '\n';
        cout << " good j: " << good[j] << " bad j: " << bad[j] << '\n';
        cout << "RES BEFORE: " << res<<'\n';*/
        if (i == j) {
            res += ((good[i]+bad[i])/2);
        } else {
            int amt = min(bad[i], bad[j]);
            res += amt;
            bad[i] -= amt;
            bad[j] -= amt;
            //cout << " amt = " << amt << '\n';
            if (bad[i] < bad[j]) {
                res += max((good[i]-min(bad[j],good[i]))/2 + min(bad[j], good[i]), good[i]/2);
                res += good[j]/2;
            } else if (bad[j] < bad[i]){
                res += max((good[j]-min(bad[i],good[j]))/2 + min(bad[i], good[j]), good[j]/2);
                res += good[i]/2;
            } else {
                res += good[i]/2;
                res += good[j]/2;
            }
        }
        good[i] = good[j] = bad[i] = bad[j] = 0;
        //cout << "RES AFTER: " << res << '\n';
    }
    cout << res << '\n';
}
/*

 */