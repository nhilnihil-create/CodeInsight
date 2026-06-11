#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

ll n, Q, k;
struct treedata {
    int pos; ll dist;
};
vector< vector<treedata> > graphlist(100100, vector<treedata>());
vector<ll> distgraph(100100, -1);

int main() {
    cin >> n;
    for(int i = 0; i < n-1; ++i) {
        int aa, bb;
        ll cc;
        cin >> aa >> bb >> cc;
        aa--; bb--;
        treedata indata;
        indata.pos = bb; indata.dist = cc;
        graphlist.at(aa).emplace_back(indata);
        indata.pos = aa;
        graphlist.at(bb).emplace_back(indata);
    }
    // cout << "ok" << endl;

    cin >> Q >> k;
    k--;
    queue<treedata> que;
    treedata first;
    first.pos = k; first.dist = 0;
    que.push(first);
    distgraph.at(k) = 0;

    while(!que.empty()) {
        treedata now = que.front();
        que.pop();
        for(int i = 0; i < (int)graphlist.at(now.pos).size(); ++i) {
            int npos = graphlist.at(now.pos).at(i).pos;
            ll ndist = graphlist.at(now.pos).at(i).dist + now.dist;
            if(distgraph.at(npos) == -1) {
                distgraph.at(npos) = ndist;
                treedata next;
                next.pos = npos; next.dist = ndist;
                que.push(next);
            }
        }
    }

    for(int i = 0; i < Q; ++i) {
        int xx, yy;
        cin >> xx >> yy;
        xx--; yy--;
        ll ans = 0;
        ans += distgraph.at(xx);
        ans += distgraph.at(yy);
        cout << ans << endl;
    }
}