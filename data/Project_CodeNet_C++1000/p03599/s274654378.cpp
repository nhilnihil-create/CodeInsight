#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

bool water[3005];
bool sugar[3005];

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int index = 0;
    a *= 100;
    b *= 100;
    while (a*index<=3000) {
        water[a*index] = true;
        index++;
    }
    rep(i, 3001) {
        if (water[i]) continue;
        if (i-b>=0 && water[i-b]) water[i] = true;
    }
    index = 0;
    while (c*index<=3000) {
        sugar[c*index] = true;
        index++;
    }
    rep(i, 3001) {
        if (sugar[i]) continue;
        if (i-d>=0 && sugar[i-d]) sugar[i] = true;
    }

    P ans = P(0, 0);
    double v = 0.0;

    rep(i, 3001) rep(j, 3001) {
        if (!water[i]) continue;
        if (!sugar[j]) continue;
        if (i==0 || j==0) continue;
        int sum = i+j;
        if (i+j>f) continue;
        double p = 100.0*j/(i);
        if (p>e) continue;
        if (p>v) {
            ans = P(i, j);
            v = p;
        }
    }

    if (ans==P(0, 0)) {
        ans.first = a;
    }
    
    cout << ans.first+ans.second << " " << ans.second << endl;
    return 0;
}
