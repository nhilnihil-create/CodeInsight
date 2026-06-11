#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a[110], cnt[10];

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;i++) {
        int x; cin >> x;
        cnt[min(x, 3200)/400]++;
    }

    int m = 0;
    for (int i=0;i<8;i++) m += cnt[i]>0;
    cout << max(m, 1) << " " << m+cnt[8] << endl;
}
