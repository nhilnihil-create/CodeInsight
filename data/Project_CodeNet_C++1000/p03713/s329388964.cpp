#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e10;

int main(){
    long long int h, w;
    cin >> h >> w;

    long long int ans = INF;
    vector<vector<long long int>> 
    a = {
            { h / 3      * w, (h - h / 3)     / 2 * w},
            {(h / 3 + 1) * w, (h - h / 3 - 1) / 2 * w},
            { h / 3      * w, (h - h / 3)     * (w / 2)},
            {(h / 3 + 1) * w, (h - h / 3 - 1) * (w / 2)},
            { w / 3      * h, (w - w / 3)     / 2 * h},
            {(w / 3 + 1) * h, (w - w / 3 - 1) / 2 * h},
            { w / 3      * h, (w - w / 3)     * (h / 2)},
            {(w / 3 + 1) * h, (w - w / 3 - 1) * (h / 2)}
    };
    for(int i=0; i<8; i++){
        //cout << a[i][0] << " " << a[i][1] << " " << h * w - a[i][0] - a[i][1] << endl;
        long long int diff = max({a[i][0], a[i][1], h * w - a[i][0] - a[i][1]})
                           - min({a[i][0], a[i][1], h * w - a[i][0] - a[i][1]});
        ans = min(ans, diff);
    }
    cout << ans << endl;
    return 0;
}