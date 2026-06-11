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

int a[100005], cnt[100005];
int idx[100005];
long long ans[100005];
int main(){
    int n;
    scanf("%d", &n);

    vector<int> v;
    v.eb(0);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        v.eb(a[i]);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    for(int i=1;i<=n;i++){
        a[i] = lower_bound(all(v), a[i]) - v.begin();
        cnt[a[i]]++;
        if(idx[a[i]] == 0) idx[a[i]] = i;
    }
    int sum = 0;
    for(int i=sz(v)-1;i>=1;i--){
        sum += cnt[i];
        if(i != sz(v)-1) idx[i] = min(idx[i], idx[i+1]);
        ans[idx[i]] += (v[i]-v[i-1])*1ll*sum;
    }
    for(int i=1;i<=n;i++) printf("%lld\n", ans[i]);
}