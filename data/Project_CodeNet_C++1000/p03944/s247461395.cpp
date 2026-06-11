#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int w, h, n, x, y, a;
    cin >> w >> h >> n;
    vector<int> x_1, x_2, y_1, y_2;
    x_1.push_back(0);
    x_2.push_back(w);
    y_1.push_back(0);
    y_2.push_back(h);
    rep1(i, n){
        cin >> x >> y >> a;
        if (a==1) x_1.push_back(x);
        if (a==2) x_2.push_back(x);
        if (a==3) y_1.push_back(y);
        if (a==4) y_2.push_back(y);
    }
    sort(x_1.begin(), x_1.end());
    sort(x_2.begin(), x_2.end());
    sort(y_1.begin(), y_1.end());
    sort(y_2.begin(), y_2.end());
    int ans = max(x_2[0] - x_1[x_1.size()-1], 0) * max(y_2[0] - y_1[y_1.size()-1], 0); 
    cout << ans << endl;
    //printf("%.12f", ans);
}