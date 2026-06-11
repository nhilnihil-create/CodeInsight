#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <map>
using namespace std;

typedef long long ll;
struct Point{ ll x, y; };
map<pair<ll, ll>, bool> poi;
map<pair<ll, ll>, bool> flg;

ll h, w, n;
struct Point p[100005];
ll ans[10];

ll dx[] = {1, 1, 1, 0, -1, -1, -1, 0, 0};
ll dy[] = {1, 0, -1, -1, -1, 0, 1, 1, 0};

int main()
{
    scanf("%lld %lld %lld", &h, &w, &n);

    for (ll i = 0; i < n; i++) {
        scanf("%lld %lld", &p[i].y, &p[i].x);
        poi[make_pair(p[i].y, p[i].x)] = true;
    }
    ans[0] = (h - 2) * (w - 2);
    
    for (ll i = 0; i < n; i++) {
        struct Point a = p[i];

        for (ll s = 0; s < 9; s++) {
            ll cnt = 0;
            ll ox = a.x + dx[s];
            ll oy = a.y + dy[s];

            if (ox - 1 < 1 || oy - 1 < 1) continue;
            if (ox + 1 > w || oy + 1 > h) continue;
            if (flg.count(make_pair(ox, oy))) continue;
            flg[make_pair(ox, oy)] = true;

            //            puts("------");
            for (ll j = 0; j < 9; j++) {
                ll x = ox + dx[j];
                ll y = oy + dy[j];

                if (poi.count(make_pair(y, x))) {
                    //      printf("(%lld, %lld)\n", y, x);
                    cnt++;
                }
            }
            //            puts("------");
            ans[cnt]++;
            ans[0]--;
        }
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%lld\n", ans[i]);
    }
    
    return 0;
}
