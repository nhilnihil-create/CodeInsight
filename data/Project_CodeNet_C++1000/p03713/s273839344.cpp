#include <iostream>
#include <utility>

using namespace std;
typedef long long ll;

int main(){
    ll h, w;
    cin >> h >> w;
    ll ans = h * w;
    for(int i = 0; i < 2; ++i){
        for(int j = 1; j < h; ++j){
            const ll p1 = j * w;
            if(h - j > 1){
                const ll p2 = (h - j) / 2 * w;
                const ll p3 = ((h - j) - (h - j) / 2) * w;
                const ll maxp = max(max(p1, p2), p3);
                const ll minp = min(min(p1, p2), p3);
                ans = min(ans, maxp - minp);
            }
            {
                const ll p2 = (h - j) * (w / 2);
                const ll p3 = (h - j) * (w - w / 2);
                const ll maxp = max(max(p1, p2), p3);
                const ll minp = min(min(p1, p2), p3);
                ans = min(ans, maxp - minp);
            }
        }
        swap(h, w);
    }
    cout << ans << endl;
    return 0;
}
