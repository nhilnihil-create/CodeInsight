#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int N;
int a[100100];

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N) cin >> a[i];
    int ans1 = 0;
    int now = 0;
    rep(i, N) {
        if (i%2==0) {
            if (now+a[i]>0) now += a[i];
            else {
                ans1 += 1-(now+a[i]);
                now = 1;
            }
        }
        else {
            if (now+a[i]<0) now += a[i];
            else {
                ans1 += now+a[i]-(-1);
                now = -1;
            }
        }
    }
    int ans2 = 0;
    now = 0;
    rep(i, N) {
        if (i%2==1) {
            if (now+a[i]>0) now += a[i];
            else {
                ans2 += 1-(now+a[i]);
                now = 1;
            }
        }
        else {
            if (now+a[i]<0) now += a[i];
            else {
                ans2 += now+a[i]-(-1);
                now = -1;
            }
        }
    }
    cout << min(ans1, ans2) << endl;
}