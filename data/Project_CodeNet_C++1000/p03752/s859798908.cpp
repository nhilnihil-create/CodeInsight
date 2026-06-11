#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int main(void)
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 1e18;
    rep(i, 1<<n)
    {
        if(__builtin_popcount(i) < k) continue;
        int preHight = 0;
        ll tmpAns = 0;
        rep(j, n)
        {
            if(i>>j&1){
                if(preHight >= a[j]){
                    tmpAns += preHight + 1 - a[j];
                    preHight++;
                }
                else
                {
                    preHight = a[j];
                }
            }
            preHight = max(preHight, a[j]);
        }
        ans = min(ans, tmpAns);
    }
    cout << ans << endl;
    return 0;
}