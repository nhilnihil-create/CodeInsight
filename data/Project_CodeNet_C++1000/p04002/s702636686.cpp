#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

set<pii> vis;
vector<pii> v;
ll ans[10];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int h, w, n;
    cin >> h >> w >> n;   
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        vis.insert(mp(a, b));
        for(int i=max(1, a-2);i<=a;i++){
            for(int j=max(1, b-2);j<=b;j++){
                v.eb(mp(i, j));
            }
        }
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    for(int i=0;i<sz(v);i++){
        int y = v[i].fi, x = v[i].se;
        if(y <= h-2 && x <= w-2){
            int cnt = 0;
            for(int j=y;j<=y+2;j++){
                for(int k=x;k<=x+2;k++){
                    if(vis.find(mp(j, k)) != vis.end()) cnt++;
                }
            }
            ans[cnt]++;
        }
    }
    ll sum = 0;
    for(int i=1;i<10;i++) sum += ans[i];
    ans[0] += (h-2)*1ll*(w-2) - sum;
    for(int i=0;i<10;i++) printf("%lld\n", ans[i]);
}