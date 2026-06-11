#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

int ft[200005];
void update(int i, int v){
    for(;i<=200002;i+=(i&-i)) ft[i] += v;
}
int query(int i){
    int res = 0;
    for(;i>0;i-=(i&-i)) res+=ft[i];
    return res;
}

int a[200005];
int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    vector<ll> h;
    h.eb(0);

    ll sum = 0;
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        sum += a[i]-k;
        h.eb(sum);
    }   
    sort(all(h));
    h.erase(unique(all(h)), h.end());

    int idx = lower_bound(all(h), 0) - h.begin() + 1;
    update(idx, 1);
    sum = 0;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        sum += a[i]-k;
        int idx = lower_bound(all(h), sum) - h.begin() + 1;
        ans += query(idx);
        update(idx, 1);
    }
    printf("%lld\n", ans);
}