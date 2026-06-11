#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 1e5 + 5;

int a[maxn];
int k;
int n;

ll pre[maxn], suf[maxn];
ll sum[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    pre[0] = 0;suf[n + 1] = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + max(0, a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = n;i >= 1;i--){
        suf[i] = suf[i + 1] + max(0, a[i]);
    }
    ll ans = 0;
    for(int i = 1;i + k - 1 <= n;i++){
        ll tmp = max(sum[i + k - 1] - sum[i - 1], 0LL) + pre[i - 1] + suf[i + k];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
