#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
//#define int long long
template<class T, class U> inline bool chmax(T& a,U b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class U> inline bool chmin(T& a,U b) { if (a > b) { a = b; return 1; } return 0; }
template<class Monoid> struct SegmentTree {
    int n; Monoid id;
    vector<Monoid> node;
    SegmentTree(int sz) {
        id = numeric_limits<Monoid>::max();
        n = 1; while (n < sz) n *= 2;
        node.resize(2*n-1, id);
    }
    void update(int x, int val) {
        x += (n-1); node[x] = val;
        while (x > 0) {
            x = (x-1)/2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }
    // minimum [a, b)
    Monoid query(int a, int b, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return id;
        if (a <= l && r <= b) return node[k];
        int vl = query(a, b, 2*k+1, l, (l+r)/2);
        int vr = query(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<pair<int, int>> sec;
    SegmentTree<int> sg(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i]; sg.update(i, A[i]);
    }
    
    auto Binary_Search = [&](int i)->pair<int, int> {
        int ok = i, l = -1, r = N;
        while (abs(ok - l) > 1) {
            int mid = (ok + l) / 2;
            if (sg.query(mid, i+1) == A[i]) ok = mid;
            else l = mid;
        }
        l = ok; ok = i;
        while (abs(ok - r) > 1) {
            int mid = (ok + r) / 2;
            if (sg.query(i, mid+1) == A[i]) ok = mid;
            else r = mid;
        }
        r = ok;
        return make_pair(l, r);
    };
    
    for (int i = 0; i < N; i++) sec.emplace_back(Binary_Search(i));
    
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int l = abs(sec[i].first-i)+1, r = abs(sec[i].second-i)+1;
        ans += (long long)l * r * A[i];
    }

    cout << ans << endl;
    return 0;
}