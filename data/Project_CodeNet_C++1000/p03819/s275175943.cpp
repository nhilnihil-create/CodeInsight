#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct segtree{
    int size;
    vector<ll> dat;
    ll init = 0;

    segtree (int N) {
        size = 1;
        while (size < N) size *= 2;
        dat = vector<ll>(2*size-1, init);
    }

    ll op(ll a, ll b) {
        return a+b;
    }

    void update(int i, ll x) { 
        i += size-1;
        dat[i] = x;
        while (i > 0) {
            i = (i-1)/2;
            dat[i] = op(dat[2*i+1], dat[2*i+2]);
        }
        return;
    }
    
    void add(int i, ll x) { 
        i += size-1;
        dat[i] += x;
        while (i > 0) {
            i = (i-1)/2;
            dat[i] = op(dat[2*i+1], dat[2*i+2]);
        }
        return;
    }

    ll query(int a, int b) {
        return query(a, b, 0, 0, size);
    }
    

    ll query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return init;
        if (a <= l && r <= b) return dat[k];
        ll lv, rv;
        lv = query(a, b, 2*k+1, l, (l+r)/2);
        rv = query(a, b, 2*k+2, (l+r)/2, r);
        return op(lv, rv);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, pair<int, int>>> omiya(N);
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        omiya[i] = {r-l+1, {l, r}};
    }
    sort(omiya.begin(), omiya.end());
    segtree st(M+3);
    int pos = 0;
    for (int i = 1; i <= M; i++) {
        while (pos < N && omiya[pos].first < i) {
            auto p = omiya[pos].second;
            st.add(p.first, 1);
            st.add(p.second+1, -1);
            pos++;
        }
        int ans = N-pos;
        for (int j = i; j <= M; j += i) {
            ans += st.query(0, j+1);
        }
        cout << ans << "\n";
    }
    return 0;
}
