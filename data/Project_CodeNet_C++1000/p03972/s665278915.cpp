#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int main()
{
    int h, w;
    cin >> h >> w;
    ll p[100002], q[100002];
    P r[200002];
    for(int i = 0; i < h; i++){
        cin >> p[i];
        r[i] = P(p[i], 0);
    }
    for(int i = 0; i < w; i++){
        cin >> q[i];
        r[i + h] = P(q[i], 1);
    }
    sort(r, r + h + w);
    int x = 0, y = 0;
    ll ans = 0;
    for(int i = 0; i < h + w; i++){
        if(r[i].second == 0){
            ans += r[i].first * (w - y + 1);
            x++;
        }
        else{
            ans += r[i].first * (h - x + 1);
            y++;
        }
    }
    cout << ans << endl;
}