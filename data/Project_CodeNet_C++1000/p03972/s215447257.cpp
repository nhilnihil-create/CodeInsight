#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma optimize("JARU SOSISONI")

using namespace std;

#define int long long
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define geometry cout.setf(ios::fixed); cout.precision(15);
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 100;
const int MOD1 = 998244353;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
const int nul = 0;
const int SIZE = 1e6 * 3;


signed main() {
#ifdef parasha
    freopen("A.in", "r", stdin);
#endif // parasha
    fast;
    int w, h;
    cin >> w >> h;
    int cntw = w + 1, cnth = h + 1;
    vector<int> p(w), q(h);
    for (int &i : p) cin >> i;
    for (int &i : q) cin >> i;
    vector<vector<int> > smth;
    for (int i = 0; i < w; i++) {
        smth.push_back({p[i], 1, i});
    }
    for (int i = 0; i < h; i++) {
        smth.push_back({q[i], 2, i});
    }
    //cout << 888 << endl;
    sort(all(smth));
    int ans = 0;
    set<int> existh, existw;
    for (int i = 0; i < h; i++) existh.insert(i);
    for (int i = 0; i < w; i++) existw.insert(i);
    for (int i = 0; i < h + w; i++) {
        //cout << smth[i][0] << " " << smth[i][1] << " " << smth[i][2] << endl;
        if (smth[i][1] == 1) {
            ans += smth[i][0] * cnth;
            cntw--;
            int x = smth[i][2];
            //if (existw.find(x - 1) == existw.end() && existw.find(x + 1) == existw.end()) cntw--;
            existw.erase(x);
        } else {
            //cout << 777 << endl;
            ans += smth[i][0] * cntw;
            cnth--;
            int x = smth[i][2];
            //if (existh.find(x - 1) == existh.end() && existh.find(x + 1) == existh.end()) cntw--;
            existh.erase(x);
        }
        //cout << ans << endl;
    }
    cout << ans << endl;

}










