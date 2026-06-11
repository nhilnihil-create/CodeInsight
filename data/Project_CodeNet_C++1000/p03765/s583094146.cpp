#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct SegmentTree {
private:
    int n;
    vector<int> node;

public:
    SegmentTree(vector<int> v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[2*i+1] + node[2*i+2];
    }

    void update(int x, int val) {
        x += (n - 1);
        node[x] += val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = node[2*x+1] + node[2*x+2];
        }
    }

    int getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];

        int vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        int vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    int q;
    cin >> q;

    vector<int> sv(s.size());
    vector<int> tv(t.size());

    rep(i, s.size()) {
        if (s[i] == 'A') sv[i] = 1;
        else sv[i] = 2;
    }

    rep(i, t.size()) {
        if (t[i] == 'A') tv[i] = 1;
        else tv[i] = 2;
    }

    SegmentTree seg_s(sv);
    SegmentTree seg_t(tv);

    rep(i, q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        if (seg_s.getsum(a, b+1) % 3 == seg_t.getsum(c, d+1) % 3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
