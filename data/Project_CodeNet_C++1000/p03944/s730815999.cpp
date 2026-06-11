#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int w, h, n;
    cin >> w >> h >> n;
    int w1 = 0, w2 = w, h1 = 0, h2 = h;
    rep(i, n) {
        int x, y, a;
        cin >> x >> y >> a;
        if(a == 1) w1 = max(w1, x);
        if(a == 2) w2 = min(w2, x);
        if(a == 3) h1 = max(h1, y);
        if(a == 4) h2 = min(h2, y);
        }

        cout << max(w2 - w1, 0) * max(h2 - h1, 0) << endl;

    return 0;
}