#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> piipi;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

int a[100005];
ll sum[100005], cnt[100005];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    ll ans = 0;
    for(int i=2;i<=n;i++){
        if(a[i-1] <= a[i]){
            ans += a[i]-a[i-1];
            if(a[i-1] < a[i]){
                cnt[a[i-1]+2]++;
                cnt[a[i]+1]--;
                sum[a[i]+1] -= a[i]-a[i-1]-1;
            }
        }
        else{
            ans += m-a[i-1]+a[i];
            cnt[1]++;
            cnt[a[i]+1]--;
            cnt[a[i-1]+2]++;
            sum[1] += m-a[i-1]-1;
            sum[a[i]+1] -= m-a[i-1]+a[i]-1;
        }
    }

    ll res = 0;
    for(int i=1;i<=m;i++){
        cnt[i] += cnt[i-1];
        sum[i] += sum[i-1];
        sum[i] += cnt[i];
        res = max(res, sum[i]);
    }
    ans -= res;
    printf("%lld\n", ans);
}