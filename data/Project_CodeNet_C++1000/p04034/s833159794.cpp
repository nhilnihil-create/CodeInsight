//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> se;
    se.insert(1);
    vi cou(n, 1);
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        cou[x-1]--;
        cou[y-1]++;
        set<int>::iterator itr = se.find(x);
        if(se.end() == itr) continue;
        if(cou[x-1] == 0) {
            se.erase(itr);
        }
        se.insert(y);
    }

    cout << (int)se.size() << endl;
}