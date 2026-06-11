#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N, x;
int a[2010];

struct segtree {
    int size;
    vector<int> node;
    
    segtree(int n) {
        size = 1;
        while (size<n) size *= 2;
        node.resize(2*size-1);
        fill(node.begin(), node.end(), 1000000000000000);
    }

    void update(int k, int a) {
        k += size-1;
        node[k] = a;
        while (k>0) {
            k = (k-1)/2;
            node[k] = min(node[2*k+1], node[2*k+2]);
        }
    }
    
    int query(int a, int b, int k, int l, int r) {
        if (r<=a || b<=l) return 1000000000000000;
        if (a<=l && r<=b) return node[k];
        else {
            int vl = query(a, b, 2*k+1, l, (l+r)/2);
            int vr = query(a, b, 2*k+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }
    
    int get(int a, int b) {
        return query(a, b, 0, 0, size);
    }
};
 
signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> x;
    rep(i, N) cin >> a[i];
    segtree st(2*N);
    rep(i, 2*N) st.update(i, a[i%N]);
    int ans = 1000000000000000;
    rep(d, N) {
        int ans_cand = x*d;
        rep(i, N) ans_cand += st.get(N+i-d, N+i+1);
        ans = min(ans, ans_cand);
    }
    cout << ans << endl;
}